#include "calculate.h"
int main(){
	Clock_Set();
	GPIO_SET();
	glcd_on();
	glcd_clear_all();
	//start 
	RNG->CR=(1<<2);
	x11=RNG->DR;
	x1=round(x11/0x0af0ffff);
	Delay(1);
	sprintf(ax1,"%.0f",x1);
	x22=RNG->DR;
	x2=round(x22/0x0af0ffff);
	Delay(1);
	sprintf(ax2,"%.0f",x2);
	x33=RNG->DR;
	x3=round(x33/0x0af0ffff);
	Delay(1);
	sprintf(ax3,"%.0f",x3);
	x44=RNG->DR;
	x4=round(x44/0x0af0ffff);
	Delay(1);
	sprintf(ax4,"%.0f",x4);
	x55=RNG->DR;
	x5=round(x55/0x0af0ffff);
	Delay(1);
	sprintf(ax5,"%.0f",x5);
	x66=RNG->DR;
	x6=round(x66/0x0af0ffff);
	Delay(1);
	sprintf(ax6,"%.0f",x6);
	x77=RNG->DR;
	x7=round(x77/0x0af0ffff);
	Delay(1);
	sprintf(ax7,"%.0f",x7);
	x88=RNG->DR;
	x8=round(x88/0x0af0ffff);
	Delay(1);
	sprintf(ax8,"%.0f",x8);
	x99=RNG->DR;
	x9=round(x99/0x0af0ffff);
	Delay(1);
	sprintf(ax9,"%.0f",x9);
	glcd_disp_Image(brocket,0,127,0,7);
	glcd_puts("A=",5,3);
		for(int j=0;j<9;j++){
			if(j==0)
			glcd_puts(ax1,30,1);
		if(j==1)
			glcd_puts(ax2,60,1);
		if(j==2)
			glcd_puts(ax3,90,1);
		if(j==3)
			glcd_puts(ax4,30,3);
		if(j==4)
			glcd_puts(ax5,60,3);
		if(j==5)
			glcd_puts(ax6,90,3);
		if(j==6)
			glcd_puts(ax7,30,5);
		if(j==7)
			glcd_puts(ax8,60,5);
		if(j==8)
			glcd_puts(ax9,90,5);
	}
	float array[9]={x1,x2,x3,x4,x5,x6,x7,x8,x9};
	float array2[9]={x1+1,x2,x3+4,x4-6,x5+3,x6+5,x7-4,x8+6,x9-4};
	sprintf(ax1,"%.0f",array2[0]);
	sprintf(ax2,"%.0f",array2[1]);
	sprintf(ax3,"%.0f",array2[2]);
	sprintf(ax4,"%.0f",array2[3]);
	sprintf(ax5,"%.0f",array2[4]);
	sprintf(ax6,"%.0f",array2[5]);
	sprintf(ax7,"%.0f",array2[6]);
	sprintf(ax8,"%.0f",array2[7]);
	sprintf(ax9,"%.0f",array2[8]);
	Delay(3000000);
	glcd_disp_Image(brocket,0,127,0,7);
	glcd_puts("B=",5,3);
		for(int j=0;j<9;j++){
			if(j==0)
			glcd_puts(ax1,30,1);
		if(j==1)
			glcd_puts(ax2,60,1);
		if(j==2)
			glcd_puts(ax3,90,1);
		if(j==3)
			glcd_puts(ax4,30,3);
		if(j==4)
			glcd_puts(ax5,60,3);
		if(j==5)
			glcd_puts(ax6,90,3);
		if(j==6)
			glcd_puts(ax7,30,5);
		if(j==7)
			glcd_puts(ax8,60,5);
		if(j==8)
			glcd_puts(ax9,90,5);	
	}
	Delay(3000000);
	//end
	arm_matrix_instance_f32		matrix1;
	arm_matrix_instance_f32		matrix2;
	arm_matrix_instance_f32		answer;
	arm_mat_init_f32(&matrix1,3,3,array);
	arm_mat_init_f32(&matrix2,3,3,array2);
	float mm[9];
	arm_mat_init_f32(&answer,3,3,mm);
	arm_mat_mult_f32(&matrix1,&matrix2,&answer);
	float32_t *a=answer.pData;
	char c[7];
	glcd_disp_Image(large_brocket,0,127,0,7);
	for(int i=0;i<9;i++){
	sprintf (c,"%.1f",a[i]);
		if(i==0){

			glcd_puts(c,5,1);
		}
		if(i==1){

			glcd_puts(c,50,1);
		}
		if(i==2){

			glcd_puts(c,90,1);
			
		}
		if(i==3){

			glcd_puts(c,5,3);
		}
		if(i==4){

			glcd_puts(c,50,3);
		}
		if(i==5){

			glcd_puts(c,90,3);

		}
		if(i==6){
			glcd_puts(c,5,5);
		}
		if(i==7){
			glcd_puts(c,50,5);
		}
		if(i==8){
			glcd_puts(c,90,5);
		}
		
		
	}
	while(1){
		
		
		
	}
}
