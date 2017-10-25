/*
######################################################################
#                              Lluita                                #
######################################################################
*/
void punch()
{
	t=0;
	t_ant=millis();
	while(t<T_PUNCH/2)
	{
		zd=HBASE-(H_ATAC)*sin(w_PUNCH*t);
		ze=HBASE-(H_ATAC)*sin(w_PUNCH*t);
		xd=0;
		xe=0;
		yd=EGy+YBASE-Y_ATAC*sin(w_PUNCH*t);
		ye=EGy+YBASE+Y_ATAC*sin(w_PUNCH*t);
		//brassos
		aa[CD-1]=a0[CD-1]+243*sin(w_PUNCH*t);
		aa[BD-1]=a0[BD-1]+130*sin(w_PUNCH*t);
		aa[BE-1]=a0[BE-1]-130*sin(w_PUNCH*t);
		aa[ZD-1]=a0[ZD-1]+123*sin(w_PUNCH*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	zd=HBASE;	ze=HBASE;	xd=0;	xe=0;	yd=EGy+YBASE;	ye=EGy+YBASE;
	//brassos
	aa[CD-1]=a0[CD-1];	aa[BD-1]=a0[BD-1];	aa[BE-1]=a0[BE-1];	aa[ZD-1]=a0[ZD-1];
	posiciona();
}

void iji()
{
	t=0;
	t_ant=millis();
	while(t<T_PUNCH/2)
	{
		zd=HBASE-(H_ATAC)*sin(w_PUNCH*t);
		ze=HBASE-(H_ATAC)*sin(w_PUNCH*t);
		xd=0;
		xe=0;
		yd=EGy+YBASE-(Y_ATAC+15)*sin(w_PUNCH*t);
		ye=EGy+YBASE+(Y_ATAC+15)*sin(w_PUNCH*t);
		//brassos
		aa[BD-1]=a0[BD-1]+130*sin(w_PUNCH*t);
		aa[BE-1]=a0[BE-1]-130*sin(w_PUNCH*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	zd=HBASE;	ze=HBASE;	xd=0;	xe=0;	yd=EGy+YBASE;	ye=EGy+YBASE;
	//brassos
	aa[CD-1]=a0[CD-1];	aa[BD-1]=a0[BD-1];	aa[BE-1]=a0[BE-1];	aa[ZD-1]=a0[ZD-1];
	posiciona();
}

void iji_2()
{
	t=0;
	t_ant=millis();
	while(t<T_PUNCH/4)
	{
		zd=HBASE-(H_ATAC)*sin(w_PUNCH*t);
		ze=HBASE-(H_ATAC)*sin(w_PUNCH*t);
		xd=0;
		xe=0;
		yd=EGy+YBASE-(Y_ATAC+15)*sin(w_PUNCH*t);
		ye=EGy+YBASE+(Y_ATAC+15)*sin(w_PUNCH*t);
		//brassos
		aa[BD-1]=a0[BD-1]+130*sin(w_PUNCH*t);
		aa[BE-1]=a0[BE-1]-130*sin(w_PUNCH*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	ps2x.read_gamepad();
	unsigned long t_ant_reg=millis();
	while(ps2x.Button(PSB_CIRCLE))
	{
		//brassos
		aa[BD-1]=a0[BD-1]+130*sin(w_PUNCH*t);
		aa[BE-1]=a0[BE-1]-130*sin(w_PUNCH*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
		if(millis() - t_ant_reg > ((1000.0*T_PUNCH)/2))
		{
			ps2x.read_gamepad();
			t=0;
			t_ant_reg=millis();
		}  
	}
	t=T_PUNCH/4;
	while(t<T_PUNCH/2)
	{
		zd=HBASE-(H_ATAC)*sin(w_PUNCH*t);
		ze=HBASE-(H_ATAC)*sin(w_PUNCH*t);
		xd=0;
		xe=0;
		yd=EGy+YBASE-(Y_ATAC+15)*sin(w_PUNCH*t);
		ye=EGy+YBASE+(Y_ATAC+15)*sin(w_PUNCH*t);
		//brassos
		aa[BD-1]=a0[BD-1]+130*sin(w_PUNCH*t);
		aa[BE-1]=a0[BE-1]-130*sin(w_PUNCH*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	zd=HBASE;	ze=HBASE;	xd=0;	xe=0;	yd=EGy+YBASE;	ye=EGy+YBASE;
	//brassos
	aa[CD-1]=a0[CD-1];	aa[BD-1]=a0[BD-1];	aa[BE-1]=a0[BE-1];	aa[ZD-1]=a0[ZD-1];
	posiciona();
}

void grapa()
{
	t=0;
	t_ant=millis();
	bool grapat=false;
	S(BE,a0[BE-1]-20);
	while(t<T_GRAP)
	{
		if(t<T_GRAP/4  || grapat)//Moviment de cames
		{
			if(t<T_GRAP/4)//Va cap al robot
			{
				zd=HBASE-(HBASE-160)*sin(w_GRAP*t);
				ze=HBASE-(HBASE-160)*sin(w_GRAP*t);
				aa[CO-1]=a0[CO-1]-120*sin(w_GRAP*t);
				xd=0;
				xe=0;
			}
			else if(t> 3*T_GRAP/4)//Recupera la posicio
			{
				zd=HBASE-(HBASE-160)*sin(w_GRAP*t-PI);
				ze=HBASE-(HBASE-160)*sin(w_GRAP*t-PI);
				aa[CO-1]=a0[CO-1]-120*sin(w_GRAP*t-PI);
			}
			yd=EGy+YBASE-90*sin(w_GRAP*t);
			ye=EGy+YBASE+90*sin(w_GRAP*t);
		}
		else//Gest de Grapar
		{
			if(t>3*T_GRAP/4)
			{
				t=T_GRAP/4;
				grapat=true;
			}
			else if(t<T_GRAP/2)//Estirar braços
			{
				aa[ED-1]=a0[ED-1]+150*sin(w_GRAP*t-PI/2);
				aa[EE-1]=a0[EE-1]-150*sin(w_GRAP*t-PI/2);
				aa[CD-1]=a0[CD-1]+175*sin(w_GRAP*t-PI/2);
				aa[CE-1]=a0[CE-1]-140*sin(w_GRAP*t-PI/2);
				aa[ZD-1]=a0[ZD-1]-122*sin(w_GRAP*t-PI/2);
				aa[ZE-1]=a0[ZE-1]+122*sin(w_GRAP*t-PI/2);
				S(BE,a0[BE-1]-40);
				S(BD,a0[BD-1]+40);
			}
			else //Els grapa
			{
				aa[BE-1]=a0[BE-1]+30*sin(w_GRAP*t-PI);
				aa[BD-1]=a0[BD-1]-30*sin(w_GRAP*t-PI);
				aa[CD-1]=a0[CD-1]+175-20*sin(w_GRAP*t-PI);
				aa[CE-1]=a0[CE-1]-140+20*sin(w_GRAP*t-PI);
			}
		}
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	t=0;
	t_ant=millis();
	while(t<T_GRAP/4)//El deixa anar
	{
		aa[BE-1]=a0[BE-1]+30*cos(w_GRAP*t);
		aa[BD-1]=a0[BD-1]-30*cos(w_GRAP*t);
		aa[CD-1]=a0[CD-1]+(175-20)*cos(w_GRAP*t);
		aa[CE-1]=a0[CE-1]-(140+20)*cos(w_GRAP*t);
		aa[ED-1]=a0[ED-1]+150*cos(w_GRAP*t);
		aa[EE-1]=a0[EE-1]-150*cos(w_GRAP*t);
		aa[ZD-1]=a0[ZD-1]-122*cos(w_GRAP*t);
		aa[ZE-1]=a0[ZE-1]+122*cos(w_GRAP*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	S(ED,a0[ED-1]);	S(EE,a0[EE-1]);	S(CD,a0[CD-1]);	S(CE,a0[CE-1]);	S(BE,a0[BE-1]);	S(BD,a0[BD-1]);	S(ZE,a0[ZE-1]);	S(ZD,a0[ZD-1]);	aa[CO-1]=a0[CO-1];
	xd=0;	xe=0;	zd=HBASE;	ze=HBASE;	ye=EGy+YBASE;	yd=EGy+YBASE;
	posiciona();
}

void moli()
{
	t=0;
	t_ant=millis();
	while(t < T_MOLI/4.0)
	{
		xd=0+X_MOLI*sin(w_MOLI*t);
		xe=0-X_MOLI*sin(w_MOLI*t);
		zd=HBASE-(HBASE-HMOLI)*sin(w_MOLI*t);
		ze=HBASE-(HBASE-HMOLI)*sin(w_MOLI*t);
		ye=EGy+YBASE+(Y_MOLI-YBASE)*sin(w_MOLI*t);
		yd=EGy+YBASE+(Y_MOLI-YBASE)*sin(w_MOLI*t);
		aa[CO-1]=a0[CO-1]-CINT_MOLI*sin(w_MOLI*t);
		S(BE,a0[BE-1]-40*sin(w_MOLI*t));
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	t=0;
	t_ant=millis();
	while(t < T_MOLI/4.0)
	{
		aa[BD-1]=a0[BD-1]+110*sin(w_MOLI*t);
		aa[CD-1]=a0[CD-1]+220*sin(w_MOLI*t);
		aa[ZD-1]=a0[ZD-1]+110*sin(w_MOLI*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	//Gir de cintura killer
	t=T_MOLI/4.0;
	t_ant=millis();
	while(t < (3.0*T_MOLI)/4.0)
	{
		aa[CO-1]=a0[CO-1]-CINT_MOLI*sin(w_MOLI*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	delay(1000);
	t=T_MOLI/4.0;
	t_ant=millis();
	while(t < T_MOLI/2.0)
	{
		aa[BD-1]=a0[BD-1]+110*sin(w_MOLI*t);
		aa[CD-1]=a0[CD-1]+220*sin(w_MOLI*t);
		aa[ZD-1]=a0[ZD-1]+110*sin(w_MOLI*t);
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}
	//Fi gir de cintura killer
	t=T_MOLI/4.0;
	t_ant=millis();
	while(t < T_MOLI/2.0)
	{
		xd=0+X_MOLI*sin(w_MOLI*t);
		xe=0-X_MOLI*sin(w_MOLI*t);
		zd=HBASE-(HBASE-HMOLI)*sin(w_MOLI*t);
		ze=HBASE-(HBASE-HMOLI)*sin(w_MOLI*t);
		ye=EGy+YBASE+(Y_MOLI-YBASE)*sin(w_MOLI*t);
		yd=EGy+YBASE+(Y_MOLI-YBASE)*sin(w_MOLI*t);
		aa[CO-1]=a0[CO-1]+CINT_MOLI*sin(w_MOLI*t);
		S(BE,a0[BE-1]-40*sin(w_MOLI*t));
		posiciona();
		t+=(millis()-t_ant)/1000.00;
		t_ant=millis();
	}	
	xd=0;	xe=0;	zd=HBASE;	ze=HBASE;	ye=EGy+YBASE;	yd=EGy+YBASE;
	posiciona();
}
