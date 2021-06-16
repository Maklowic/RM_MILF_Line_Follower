#define true 1
#define false 0

volatile int timercount=0;
GPIO_InitTypeDef PortA;
GPIO_InitTypeDef PortE;
int Ladowanie=0;int Ladowanie2=0;
int qcontrol = 0;
int switchr = 0;
int cunter=0;int cunter2=0;
//***Odczyt ADC
int ADC_Result;
float ADC_Result1;
float Volt;
uint8_t deb1,deb2,deb3,deb4,deb5;
uint8_t sensorselect=0;
uint8_t sensors_tab[9]={0};
int isBlack(int x);
int None(){return !(sensors_tab[0] && sensors_tab[1] && sensors_tab[2] && sensors_tab[3] && sensors_tab[4] &&
		sensors_tab[5] && sensors_tab[6] && sensors_tab[7] &&sensors_tab[8]);}
enum Motor{
	Front,Back,Stop,REST
};
int Destination=REST;

void AllForth(){Control(Front, 'l'); Control(Front, 'r');}
void managedir(){	
	if(sensors_tab[4] && !(sensors_tab[3] || sensors_tab[5])){
		Control(Front,'l');
		Control(Front,'r');
		SetSpeed(15,'l');
		SetSpeed(15,'r');
	}
	else if(sensors_tab[3]&& ! sensors_tab[8]){AllForth();SetSpeed(10,'r');SetSpeed(20,'l');}
	else if(sensors_tab[5]&& ! sensors_tab[0]){AllForth();SetSpeed(10,'l');SetSpeed(20,'r');}

	else if(sensors_tab[2] && ! sensors_tab[8]){AllForth();SetSpeed(2,'r');SetSpeed(25,'l');}
	else if(sensors_tab[6] && ! sensors_tab[0]){AllForth();SetSpeed(2,'l');SetSpeed(25,'r');}

	else if(sensors_tab[0]){Control(Back, 'l'); SetSpeed(30,'r');SetSpeed(20,'l');}
	else if(sensors_tab[8]){Control(Back, 'r'); SetSpeed(30,'l');SetSpeed(20,'r');}
}

void SenSelect(){
	switch(sensorselect){
	case 0:
		if(GPIO_ReadInputDataBit(GPIO, GPIO_Pin_) == 0){
		if(isBlack(cunter))sensors_tab[0]=1;
		else sensors_tab[4]=0;
		deb5=sensors_tab[4];
		sensorselect=1;


		}
		break;
	case 1:
		if(GPIO_ReadInputDataBit(GPIO, GPIO_Pin_) == 0){
		if(isBlack(cunter))sensors_tab[1]=1;
		else sensors_tab[3]=0;
		deb4=sensors_tab[3];
		sensorselect=2;


		}
		break;
	case 2:
		if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_5) == 0){
		if(isBlack(cunter))sensors_tab[2]=1;
		else sensors_tab[5]=0;
		deb6=sensors_tab[5];
		sensorselect=3;
;}

		break;
	case 3:
			if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_9) == 0){
			if(isBlack(cunter))sensors_tab[3]=1;
			else sensors_tab[2]=0;
			deb3=sensors_tab[2];
			sensorselect=4;

					}
			break;
	case 4:
			if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_10) == 0){
			if(isBlack(cunter))sensors_tab[4]=1;
			else sensors_tab[6]=0;
			deb7=sensors_tab[6];
			sensorselect=7;

					}
			break;
	default:
		TIM_Cmd(TIM2, DISABLE);
		break;
	}

}

void SetSpeed(int speed, char dir){
	switch(dir){
	case 'l':
		TIM4->CCR1 = (speed+25 > 95 ? 70 : speed + 25);
		break;
	case 'r':
		TIM4->CCR3 = (speed+25 > 95 ? 70 : speed + 25);
		break;
	}
}
void Control(int Dir, char moto){
switch(moto){
case 'l':
	switch(Dir){
	case Front:
		if(Destination == Front)return;
		else {GPIO_ResetBits(GPIOB,GPIO_Pin_5 | GPIO_Pin_7);
		GPIO_SetBits(GPIOB,GPIO_Pin_7);
		}
		break;
	case Back:
		if(Destination == Back)return;
		else {GPIO_ResetBits(GPIOB,GPIO_Pin_5 | GPIO_Pin_7);
		GPIO_SetBits(GPIOB, GPIO_Pin_5);
		}
		break;
	case Stop:
		GPIO_ResetBits(GPIOB,GPIO_Pin_5 | GPIO_Pin_7);
		break;
	}
	break;

case 'r':
	switch(Dir){
	case Front:
		if(Destination == Front)return;
		else {GPIO_ResetBits(GPIOB,GPIO_Pin_4 | GPIO_Pin_9);
		GPIO_SetBits(GPIOB,GPIO_Pin_4);
		}
		break;
	case Back:
		if(Destination == Back)return;
		else {GPIO_ResetBits(GPIOB,GPIO_Pin_4 | GPIO_Pin_9);
		GPIO_SetBits(GPIOB, GPIO_Pin_9);
		}
		break;
	case Stop:
		GPIO_ResetBits(GPIOB,GPIO_Pin_4 | GPIO_Pin_9);
		break;
	}
	break;

}
}

int isBlack(x){return x>15;}

int calc_err()
{
	int err = 0;						
	int count = 0;						
	
	int weight = 10;						
	
	if(line_off)				
	weight = 5;
	
	for(int i=0; i<7; i++)
	{
		err += sensors_tab[i]*(i-3)*weight;
		count += sensors_tab[i];
	}
	
	if(count != 0)					
	{
		err /= count;					
		prev_err = err;
	}
	else							
	{
		if(prev_err < -20)				
		{
			err = -40;			
			line_off = 1;	
		}
		else if(prev_err > 20)		
		{
			err = 40;		
			line_off = 2;		
		}
		else
			err = 0;
	}
	
	if(line_off == 1 && err >= 0)
	line_off = 0;
	else if(line_off == 2 && err <= 0)
	line_off = 0;
	
	return err;
}


int PD_reg()
{
	int differential = err - pop_err;
	pop_err = err;
	
	return Kp*err + Kd*differential;
}

void PWM(int left, int right)
{
	if(left >= 0)
	{
		if(left>255)
			left = 255;
		// uzupełnić o miejsce pwm 1
		// uzupełnić o miejsce pwm 2
	}
	else
	{
		if(left<-255)
			left = -255;
		// uzupełnić o miejsce pwm 1
		// uzupełnić o miejsce pwm 2
	
	}
	
	if(right >= 0)
	{
		if(right>255)
			right = 255;
		// uzupełnić o miejsce pwm 1
		// uzupełnić o miejsce pwm 2
	}
	else
	{
		if(right<-255)
			right = -255;
		// uzupełnić o miejsce pwm 1
		// uzupełnić o miejsce pwm 2
	}
	
	PWML = abs(left);
	PWMP = abs(right);
}

void LF_loop()
{	
	SenSelect();
	int reg = PD_reg();
	PWM(V_zad + reg, V_zad - reg);
}
