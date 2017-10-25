void setup()///#####################################SETUP###################################################
{
	ude_setup();
	nivell_bateria();
	t_ant=millis();
	t=0;
}

/*######################################################################
#                                                                      #
#								 MAIN                                  ########################################################
#                                                                      # 
######################################################################*/

void loop()
{
	nivell_bateria();
	ps2x.read_gamepad();          //Lectura del mando
	if(ps2x.Button(PSB_PAD_RIGHT) ) 	_desplasamentdret(); 
	else if(ps2x.Button(PSB_PAD_LEFT))	_desplasamentesquerre();
	else if(ps2x.Button(PSB_CIRCLE))	iji_2();
	else if(ps2x.Button(PSB_SQUARE))	punch();
	else if(ps2x.Button(PSB_TRIANGLE))	grapa();
	else if(ps2x.Button(PSB_CROSS))		secret();
	else if(ps2x.Button(PSB_L1))		_giraesquerre();
	else if(ps2x.Button(PSB_R1))		_giradreta();
	else if(ps2x.Button(PSB_SELECT) && aixecat)
	{
		aixecat=false;
		agenollat();
	}
	else if(ps2x.Button(PSB_START) && !aixecat)
	{
		desagenollat();
		aixecat=true;	
	}
	
	//Serial.print("Stick Values:");
	/*/Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX  
	Serial.print(",");
	sSerial.println(ps2x.Analog(PSS_LX), DEC);/*/
	//giraesquerre(2);
	//giradreta(2);
}
