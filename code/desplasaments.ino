/*
########################################################################
#							 DESPLAÇAMENTS							   #
########################################################################
*/
void _desplasamentdret()
{
	t_ant=millis();
	t=0;
	while(ps2x.Button(PSB_PAD_RIGHT))
	{
		nivell_bateria();
		xd=-2.5*sin(w_LAT*t);
		xe=0;
		zd=HBASE-H_OSCI_LAT*cos(w_LAT*t);
		ze=HBASE+H_OSCI_LAT*cos(w_LAT*t);
		ye=EGy+YBASE-Y_OSCI_LAT*sin(w_LAT*t);
		yd=EGy+YBASE-Y_OSCI_LAT*sin(w_LAT*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
		ps2x.read_gamepad(); 
	}
	S(BE,a0[BE-1]);	S(BD,a0[BD-1]);	xd=0;	xe=0;	zd=HBASE;	ze=HBASE;	ye=EGy+YBASE;	yd=EGy+YBASE;	aa[CO-1]=a0[CO-1];
	posiciona();
}

void _desplasamentesquerre()
{
	t_ant=millis();
	t=0;
	while(ps2x.Button(PSB_PAD_LEFT))
	{
		nivell_bateria();
		xd=-5*sin(w_LAT*t);//xd=0;
		xe=0;
		zd=HBASE-H_OSCI_LAT*cos(w_LAT*t);
		ze=HBASE+H_OSCI_LAT*cos(w_LAT*t);
		ye=EGy+YBASE+Y_OSCI_LAT*sin(w_LAT*t);
		yd=EGy+YBASE+Y_OSCI_LAT*sin(w_LAT*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
		ps2x.read_gamepad(); 
	}
	S(BE,a0[BE-1]);	S(BD,a0[BD-1]);	xd=0;	xe=0;	zd=HBASE;	ze=HBASE;	ye=EGy+YBASE;	yd=EGy+YBASE;	aa[CO-1]=a0[CO-1];
	posiciona();
	ps2x.read_gamepad(); 
}

void _giraesquerre()
{
	t_ant=millis();
	t=0;
	while(ps2x.Button(PSB_L1) )
	{
		nivell_bateria();
		S(BE,a0[BE-1]-20);
		S(BD,a0[BD-1]+20);
		xd=0;
		xe=0;
		zd=HBASE+H_OSCI_GIR*sin(w_gir*t);
		ze=HBASE+H_OSCI_GIR*sin(w_gir*t);
		ye=EGy+YBASE;
		yd=EGy+YBASE;
		aa[CO-1]=a0[CO-1]+CINTURA_GIR*cos(w_gir*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
		ps2x.read_gamepad();          //Lectura del mando
	}
	S(BE,a0[BE-1]);	S(BD,a0[BD-1]);	xd=0;	xe=0;	zd=HBASE;	ze=HBASE;	ye=EGy+YBASE;	yd=EGy+YBASE;	aa[CO-1]=a0[CO-1];
	posiciona();
}

void _giradreta()
{
	t_ant=millis();
	t=0;
	while( ps2x.Button(PSB_R1) )
	{
		nivell_bateria();
		S(BE,a0[BE-1]-20);
		S(BD,a0[BD-1]+20);
		xd=0;
		xe=0;
		zd=HBASE+H_OSCI_GIR*sin(w_gir*t);
		ze=HBASE+H_OSCI_GIR*sin(w_gir*t);
		ye=EGy+YBASE;
		yd=EGy+YBASE;
		aa[CO-1]=a0[CO-1]-CINTURA_GIR*cos(w_gir*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
		ps2x.read_gamepad();  
	}
	S(BE,a0[BE-1]);	S(BD,a0[BD-1]);	xd=0;	xe=0;	zd=HBASE;	ze=HBASE;	ye=EGy+YBASE;	yd=EGy+YBASE;	aa[CO-1]=a0[CO-1];
	posiciona();
}

void giraesquerre(float _t)
{
	t_ant=millis();
	t=0;
	while(t<_t )
	{
		nivell_bateria();
		S(BE,a0[BE-1]-20);
		S(BD,a0[BD-1]+20);
		xd=0;
		xe=0;
		zd=HBASE+H_OSCI_GIR*sin(w_gir*t);
		ze=HBASE+H_OSCI_GIR*sin(w_gir*t);
		ye=EGy+YBASE;
		yd=EGy+YBASE;
		aa[CO-1]=a0[CO-1]+CINTURA_GIR*cos(w_gir*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	S(BE,a0[BE-1]);	S(BD,a0[BD-1]);	xd=0;	xe=0;	zd=HBASE;	ze=HBASE;	ye=EGy+YBASE;	yd=EGy+YBASE;	aa[CO-1]=a0[CO-1];
	posiciona();
}

void giradreta(float _t)
{
	t_ant=millis();
	t=0;
	while(t<_t )
	{
		nivell_bateria();
		S(BE,a0[BE-1]-20);
		S(BD,a0[BD-1]+20);
		xd=0;
		xe=0;
		zd=HBASE+H_OSCI_GIR*sin(w_gir*t);
		ze=HBASE+H_OSCI_GIR*sin(w_gir*t);
		ye=EGy+YBASE;
		yd=EGy+YBASE;
		aa[CO-1]=a0[CO-1]-CINTURA_GIR*cos(w_gir*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	S(BE,a0[BE-1]);	S(BD,a0[BD-1]);	xd=0;	xe=0;	zd=HBASE;	ze=HBASE;	ye=EGy+YBASE;	yd=EGy+YBASE;	aa[CO-1]=a0[CO-1];
	posiciona();
}

void lateraldret(int _times)
{
	t_ant=millis();
	t=0;
	while(t<_times*T_LAT )
	{
		nivell_bateria();
		xd=-2.5*sin(w_LAT*t);
		xe=0;
		zd=HBASE-H_OSCI_LAT*cos(w_LAT*t);
		ze=HBASE+H_OSCI_LAT*cos(w_LAT*t);
		ye=EGy+YBASE-Y_OSCI_LAT*sin(w_LAT*t);
		yd=EGy+YBASE-Y_OSCI_LAT*sin(w_LAT*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	S(BE,a0[BE-1]);	S(BD,a0[BD-1]);	xd=0;	xe=0;	zd=HBASE;	ze=HBASE;	ye=EGy+YBASE;	yd=EGy+YBASE;	aa[CO-1]=a0[CO-1];
	posiciona();
}

void lateralesquerre(int _times)
{
	t_ant=millis();
	t=0;
	while(t<_times*T_LAT )
	{
		nivell_bateria();
		xd=-5*sin(w_LAT*t);//xd=0;
		xe=0;
		zd=HBASE-H_OSCI_LAT*cos(w_LAT*t);
		ze=HBASE+H_OSCI_LAT*cos(w_LAT*t);
		ye=EGy+YBASE+Y_OSCI_LAT*sin(w_LAT*t);
		yd=EGy+YBASE+Y_OSCI_LAT*sin(w_LAT*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	S(BE,a0[BE-1]);	S(BD,a0[BD-1]);	xd=0;	xe=0;	zd=HBASE;	ze=HBASE;	ye=EGy+YBASE;	yd=EGy+YBASE;	aa[CO-1]=a0[CO-1];
	posiciona();
}



void camina(float _distancia)
{
	bool camina=true;
	t=0;
	etapa=0;
	t_ant=millis();
	while(camina || (etapa != 6  &&  etapa != 10) )
	{
		switch(etapa)
		{
			case 0://Es posa sobre el peu dret 
				ye=EGy+Y_BASE_CAMINA_LLARG + Y_OSCI_CAMINA_LLARG*sin(w_CAMINA_LLARG*t);
				yd=EGy+Y_BASE_CAMINA_LLARG - Y_OSCI_CAMINA_LLARG*sin(w_CAMINA_LLARG*t);

				if(t>T_CAMINA_LLARG/4.0)
				{
					etapa++;
					t=0;
				}
				break;
				
			case 1://Aixeca peu esquerre
				ze=HBASE-H_OSCI_CAMINA_LLARG*sin(w_CAMINA_LLARG*t);
				if(t>T_CAMINA_LLARG/4.0)
				{
					etapa++;
					t=0;
				}
				break;
				
			case 2://Avansa peu esquerre
				xe=aux_xe=-(X_OSCI_CAMINA_LLARG)*sin(w_CAMINA_LLARG*t);
				if(x_pos-xe>=_distancia)camina=false;
				if(t>T_CAMINA_LLARG/4.0 || !camina)
				{
					x_pos-=xe;//Ja que el peu treballa amb la x negativa
					etapa++;
					t=0;
				}
				break;
					
			case 3://Abaixa peu esquerre
				ze=HBASE-H_OSCI_CAMINA_LLARG*cos(w_CAMINA_LLARG*t);
				if(t>T_CAMINA_LLARG/4.0)
				{
					etapa++;
					t=0;
				}
				break;
				
			case 4://Canvi del pes d'un peu a l'altre
				ye=EGy+Y_BASE_CAMINA_LLARG+Y_OSCI_CAMINA_LLARG*cos(w_CAMINA_LLARG*t);
				yd=EGy+Y_BASE_CAMINA_LLARG -Y_OSCI_CAMINA_LLARG*cos(w_CAMINA_LLARG*t);
				xe=aux_xe*cos(w_CAMINA_LLARG*t/2.0);
				xd=-aux_xe+aux_xe*cos(w_CAMINA_LLARG*t/2.0);
				if(t>T_CAMINA_LLARG/2)
				{
					etapa++;
					t=0;
				}
				break;
			
			case 5://Aixeca peu dret
				zd=HBASE-H_OSCI_CAMINA_LLARG*sin(w_CAMINA_LLARG*t);
				if(t>T_CAMINA_LLARG/4.0)
				{
					etapa++;
					t=0;
				}
				break;
			
			case 6://Avansa peu dret
				xd=aux_xd=-aux_xe*cos(w_CAMINA_LLARG*t);
				if(t>T_CAMINA_LLARG/4.0)
				{
					if(x_pos-xd>_distancia)camina=false;
				}
				if(t>T_CAMINA_LLARG/2.0 || !camina)
				{
					x_pos-=xd;
					etapa++;
					t=0;
				}
				break;
					
			case 7://Abaixa peu dret
				zd=HBASE-H_OSCI_CAMINA_LLARG*cos(w_CAMINA_LLARG*t);
				if(t>T_CAMINA_LLARG/4.0)
				{
					etapa++;
					t=0;
				}
				break;
		
			case 8://Pes al peu dret
				ye=EGy+Y_BASE_CAMINA_LLARG -Y_OSCI_CAMINA_LLARG*cos(w_CAMINA_LLARG*t);
				yd=EGy+Y_BASE_CAMINA_LLARG +Y_OSCI_CAMINA_LLARG*cos(w_CAMINA_LLARG*t);
				xd=aux_xd*cos(w_CAMINA_LLARG*t/2.0);
				xe=-aux_xd+aux_xd*cos(w_CAMINA_LLARG*t/2.0);
				if(t>T_CAMINA_LLARG/2.0)
				{
					etapa++;
					t=0;
				}
				break;
				
			case 9://Aixeca peu esquerre
				ze=HBASE-H_OSCI_CAMINA_LLARG*sin(w_CAMINA_LLARG*t);
				if(t>T_CAMINA_LLARG/4.0)
				{
					etapa++;
					t=0;
				}
				break;
				
			case 10://Avansa peu esquerre
				xe=aux_xe=-aux_xd*cos(w_CAMINA_LLARG*t);
				if(t>T_CAMINA_LLARG/4.0)if(x_pos-xe>=_distancia)camina=false;
				if(t>T_CAMINA_LLARG/2.0 || !camina)
				{
					x_pos-=xe;
					etapa=3;
					t=0;
				}
				break;
		}
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	//Tenca el caminar
	t=0;
	t_ant=millis();
	while(etapa!=0)
	{
		switch(etapa)
		{
			case 6://Tanca dret
				xd=aux_xd=-aux_xe*cos(w_CAMINA_LLARG*t);
				if(t>T_CAMINA_LLARG/4.0)
				{
					etapa++;
					t=0;
				}
				break;
				
			case 7://Abaixa peu dret
				zd=HBASE-H_OSCI_CAMINA_LLARG*cos(w_CAMINA_LLARG*t);
				ye=EGy+Y_BASE_CAMINA_LLARG -Y_OSCI_CAMINA_LLARG*cos(w_CAMINA_LLARG*t);
				yd=EGy+Y_BASE_CAMINA_LLARG +Y_OSCI_CAMINA_LLARG*cos(w_CAMINA_LLARG*t);
				if(t>T_CAMINA_LLARG/4.0)
				{
					etapa=0;
				}
				break;
						
			
			case 10://Tanca esquerre
				xe=aux_xe=-aux_xd*cos(w_CAMINA_LLARG*t);
				if(t>T_CAMINA_LLARG/4.0)
				{
					etapa++;
					t=0;
				}
				break;
				
			case 11:
				ze=HBASE-H_OSCI_CAMINA_LLARG*cos(w_CAMINA_LLARG*t);
				ye=EGy+Y_BASE_CAMINA_LLARG+Y_OSCI_CAMINA_LLARG*cos(w_CAMINA_LLARG*t);
				yd=EGy+Y_BASE_CAMINA_LLARG -Y_OSCI_CAMINA_LLARG*cos(w_CAMINA_LLARG*t);
				if(t>T_CAMINA_LLARG/4.0)
				{
					etapa=0;
				}
				break;	
		}
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();		
	}
}
