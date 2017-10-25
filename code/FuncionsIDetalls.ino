#define	DEBUG
#define	SO
#define	CTRL_BATERIA

#include <Wire.h>
#include <PS2X_lib.h> 

#define BATERIA_MINIMA 6.5
//Parametres de Temps
#define T_CAMINA_LLARG 	1.3

#define T_ESPERA 	5000	//Temps que tarda al començar
#define T_PUNCH   	0.840//.5	//Període del cop de puny
#define T_MOLI 		1.5//2.0

#define T_GRAP    	2.0	//Període del agafat
#define T_GIR 		0.2//0.15		//Període del gir
#define T_ALSAMENT 	0.75	//Període de l'alsament
#define T_LAT 		0.20
#define T_BAIXA		4.0
//Paraetres de l'atac 
#define H_ATAC 		30.0
#define Y_ATAC 		30


#define  FC 142.0/90.0
#define SD20 0x61
#define CA_MAX 170
#define CA_MIN 10
#define INTERVAL_MESURA  10

//PINOUT
#define LED 		 8                
#define BRUN 		 6               
#define MOSFET 		 4             
#define BAT 		A3    
#define Data		10  //Taronja
#define Command		11  //Groc
#define Attention	12  //Verd
#define Clock		13  //Blau
 
//SERVOS
#define PD 1	//Servo 1
#define PE 2	//Servo 2
#define TD 3	//Servo 3
#define TE 4	//Servo 4
#define GD 6	//Servo 6
#define GE 7	//Servo 7
#define FD 8	//Servo 8
#define FE 9	//Servo 9
#define AD 10	//Servo 10
#define AE 11	//Servo 11
#define ED 12	//Servo 12
#define EE 13	//Servo 13
#define BD 14	//Servo 14
#define BE 15	//Servo 15
#define ZD 16	//Servo 16
#define ZE 17	//Servo 17
#define CD 18 	//Serv0 18 Colze gir
#define CE 19 	//Serv0 19 Colze gir
#define CO 20 	//Serv0 20 COS 

//Notes
#define  Fa     87.307		//f
#define  Sol_  103.826		//g#
#define  Si    123.471		//b

//Disseny de l'estructura
#define l   60.0
#define TA  15.0
#define AB  30.0
#define DE  30.0
#define EGz	25.0
#define EGy	35.0
#define LlargPeu 110.0

#define HBASE 200
#define YBASE 25
#define H_OSCI_GIR 3
#define CINTURA_GIR 10.0// 5.0//10
#define Y_OSCI_LAT 10//5
#define w_LAT (2.00*PI)/T_LAT
#define H_OSCI_LAT 2//5
#define w_PUNCH (2.00*PI)/T_PUNCH
#define w_gir (2.00*PI)/T_GIR
#define w_GRAP	(2.00*PI)/T_GRAP //w del agafat
#define w_LAT (2.00*PI)/T_LAT
//ESCALES
#define T_CAMINAR_ESCALONS 2.0 //està guai
#define T_PREPARA_PUJAR_ESCALONS 4.0
#define T_PUJA 6.0

#define H_OSCI_CAMINA_ESCALONS 15.0
#define Y_OSCI_CAMINA_ESCALONS 40.0
#define X_OSCI_CAMINA_ESCALONS 35.0
#define SEPARACIO_Y_CAMINAR_ESCALES 10.0
#define w_CAMINA_ESCALONS (2.00*PI)/T_CAMINAR_ESCALONS
#define w_PREPARA_PUJAR (2.00*PI)/T_PREPARA_PUJAR_ESCALONS
#define w_PUJA (2.00*PI)/T_PUJA

#define HBASE_PUJA 190 //dret fa 220  i assentat 105+25=130
#define HPAS_PUJA 55//35
#define XPAS_PUJA 10//15
#define YBASE_PUJA 5
#define YPAS_PUJA 45//30
#define elquefalta_PUJA 25

//Baixarles:

#define HBASE_BAIXA 160.0//190 //dret fa 220  i assentat 105+25=130
#define HPAS_BAIXA 55.0//35
#define XPAS_BAIXA 10.0//15
#define YBASE_BAIXA 5.0
#define YPAS_BAIXA 45.0//30
#define elquefalta_BAIXA 25.0
#define w_BAIXA  (2.0*PI)/T_BAIXA

//MOLI
#define w_MOLI (2.00*PI)/T_MOLI
#define HMOLI 	170
#define Y_MOLI 	 40
#define X_MOLI 	 40
#define CINT_MOLI 90

//Camina LLarg
#define H_OSCI_CAMINA_LLARG 15.0
#define Y_OSCI_CAMINA_LLARG 40.0
#define X_OSCI_CAMINA_LLARG 30.0//40.0
#define Y_BASE_CAMINA_LLARG	5.0
#define w_CAMINA_LLARG	 (2.00*PI)/T_CAMINA_LLARG

//Variables Globals
float aa[20];
float aux_xd,aux_xe,x_pos=0;   //                                                                            190  131.5
//				   	 BPD  BPE  BTD  BTE  X  BGD  BGE  BFD  BFE  BAD  BAE  BED  BEE  BBD  BBE  BZD  BZE  BCD  BCE  BCO
const float a0[20]={ 140, 125, 115, 145, 0, 250,   3,  50, 192, 122, 130,  80, 172,  32, 217, 122,   7,   2, 175, 127};
float a,b,c,d,e;
float zd=HBASE,t=0,ze=HBASE,xd=0,xe=0,yd=EGy+YBASE,ye=EGy+YBASE,Cos=a0[19];
unsigned long t_ant;
unsigned char etapa=0;
bool aixecat=false;

PS2X ps2x; // Creamos la clase del mando PS2
int  error = 0;   // Para reconocer el mando
byte type = 0;    // Tipo del mando. Volveremos sobre ello

void ude_setup()///#####################################SETUP###################################################
{
	Wire.begin();
	#ifdef DEBUG
		Serial.begin(9600);
	#endif
	
	//Mando
	// GamePad(clock, command, attention, data, Pressures?, Rumble?)
    error = ps2x.config_gamepad(Clock,Command,Attention,Data, false, false); 
	if(error == 0)
		Serial.println("Controlador encontrado y configurado");
	else  Serial.println("No s'ha trobat el controlador");
		type = ps2x.readType();   
	if ( type == 1) 
		Serial.println("Hallado controlador DualShock.");   
	
	pinMode(LED,OUTPUT);		//LED
	pinMode(BRUN,OUTPUT);		//BRUNZIDOR
	pinMode(MOSFET,OUTPUT);		//MOSFET per controlar l'alimentaciò dels servos
	pinMode(BAT,INPUT);			//Pin que controla la bateria
	digitalWrite(LED,LOW);		//Apaga el LED
	digitalWrite(BRUN,LOW);		//Apaga el BRUNZIDOR
	digitalWrite(MOSFET,LOW);	//Apaga el MOSFET
	setExpand();
	digitalWrite(LED,HIGH);
}

/*
########################################################################
#								 SD20								   #
########################################################################
*/

void write(unsigned char reg,unsigned char val)
{
	Wire.beginTransmission(SD20);
	Wire.write(reg);
	Wire.write(val);
	Wire.endTransmission();
	delayMicroseconds(70);
}

void setExpand()
{
	Wire.beginTransmission(SD20);
	Wire.write(21);
	Wire.write(0x24);
	Wire.endTransmission();
	delayMicroseconds(70);
	Wire.beginTransmission(SD20);
	Wire.write(22);
	Wire.write(0x02);
	Wire.write(0x44);
	Wire.endTransmission();
	delayMicroseconds(70);
}

void S(unsigned char s, int val)
{
	if(val>255)val=255;
	else if (val<1)val=1;
	if(s<21 && s>0)
	{
		write(s,char(val));
		aa[s-1]=val;
	}
}


/*
########################################################################
#								ALTRES								   #
########################################################################
*/
float nivell_bateria()
{
	float nbat=(analogRead(BAT)*(10.00/1023.00));
	#ifdef DEBUG
		Serial.println(nbat);
	#endif
	#ifdef CTRL_BATERIA
		while (nbat<BATERIA_MINIMA )
		{
			#ifdef SO
				toca(Si,120);
				delay(40);
				toca(Fa,120);
				delay(40);
			#endif
			digitalWrite(LED,LOW);
			delay(500);
			digitalWrite(LED,HIGH);
			nbat=nivell_bateria();
			#ifdef DEBUG
				Serial.println(nbat);
			#endif
		}
	#endif
	return nbat;
}

void desagenollat()
{
	basedret();
	zd=150;
	ze=150;
	xe=0;
	xd=0;
	ye=YBASE;
	yd=YBASE;
	posiciona();
	toca(Sol_,350);
	//delay(5000);
	digitalWrite(MOSFET,HIGH);
	float w_a=PI/(2.0*T_ALSAMENT);
	t=0;
	t_ant=millis();
	while(t<T_ALSAMENT)
	{
		zd=HBASE-(HBASE-150)*cos(w_a*t);
		ze=HBASE-(HBASE-150)*cos(w_a*t);
		xd=0;
		xe=0;
		yd=EGy+YBASE*sin(w_a*t);
		ye=EGy+YBASE*sin(w_a*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	zd=HBASE;	ze=HBASE;	xd=0;	xe=0;	yd=EGy+YBASE;	ye=EGy+YBASE;
	posiciona();
}

void agenollat()
{
	delay(500);
	float w_a=PI/(2.0*T_ALSAMENT);
	t=0;
	t_ant=millis();
	while(t<T_ALSAMENT)
	{
		zd=HBASE-(HBASE-135)*sin(w_a*t);
		ze=HBASE-(HBASE-140)*sin(w_a*t);
		xd=0;
		xe=0;
		yd=EGy+YBASE*cos(w_a*t);
		ye=EGy+YBASE*cos(w_a*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	digitalWrite(MOSFET,LOW);
}

void calculaangles(float x,float y,float z)
{
	float bp, bs,cp,AEz,AEy,BDz,BDx=x,BDt;
	AEz=z-TA-EGz;
	AEy=y-EGy;
	a=atan((AEy/AEz));
	e=a;
	BDz=((AEz)/cos(a)) -  (AB+DE);
	BDt=sqrt((BDx*BDx)+(BDz*BDz));
	c=PI-acos(1-((BDt*BDt)/(2*l*l)));
	b=acos( BDt / (2*l) ) + atan( BDx / BDz );
	d=c-b;
}

void toca( int _nota,int _durada)
{	
	float temps=0;
	#ifdef SO
		while (temps < _durada)
		{
			digitalWrite(BRUN,HIGH);
			delayMicroseconds(_nota/ 2);
			digitalWrite(BRUN, LOW);
			delayMicroseconds(_nota/ 2);
			temps += float(_nota)/1000.00;
		}
	#endif	
}

void posiciona()
{
	calculaangles(xd,yd,zd);
	aa[0]=(a0[0] - ((a/PI)*180*FC));
	aa[2]=a0[2] - ((b/PI)*180*FC);
	aa[5]=a0[5] - ((c/PI)*180*FC);
	aa[7]=a0[7] + ((d/PI)*180*FC);
	aa[9]=a0[9] - ((e/PI)*180*FC);
	calculaangles(xe,ye,ze);
	aa[1]=a0[1] + ((a/PI)*180*FC);
	aa[3]=a0[3] + ((b/PI)*180*FC);
	aa[6]=a0[6] + ((c/PI)*180*FC);
	aa[8]=a0[8] - ((d/PI)*180*FC);
	aa[10]=a0[10] + ((e/PI)*180*FC);
	SV();
}

void SV()
{
	for(int i=1;i<=20;i++)	S(i,aa[i-1]);
}

void basedret()
{
	for(int i=1;i<=20;i++)	S(i,a0[i-1]);
}
