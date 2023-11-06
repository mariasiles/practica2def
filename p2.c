#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 512
float Mat[N][N];
float MatDD[N][N];
float V1[N];
float V2[N];
float V3[N];
float V4[N];


void InitData(){
	int i,j;
	srand(4422543);
	for( i = 0; i < N; i++ )
		 for( j = 0; j < N; j++ ){
			  Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
			   if ( (abs(i - j) <= 3) && (i != j))
				    MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
			    else if ( i == j )
				     MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
			     else MatDD[i][j] = 0.0;
			      }
	for( i = 0; i < N; i++ ){
		 V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
		  V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
		   V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
	}
}






void PrintVect(float vect[N],int from,int numel){
	int i;
	for( i = from; i <numel+from; i++ ){
		printf("%f ",vect[i]);
	}
}

void PrintRow( float mat[N][N], int row, int from, int numel ){
	        for (int i=from; i<from+numel; i++){
			     printf("%f ",mat[row][i]);
		}
}
void MultEscalar( float vect[N], float vectres[N], float alfa ){
	for (int i=0; i<N; i++){
		vectres[i]= alfa * vect[i];
		 
	}
		
	
}

float Scalar( float vect1[N], float vect2[N] ){
	float resultat=0.0;
	for (int i=0; i<N; i++){
		
		resultat+= vect1[i] * vect2[i];
	}
	
	return resultat;
}

float Magnitude( float vect[N] ){
	int i;
	float result=0.0;
	for (i=0; i<N; i++){
		result+=vect[i]*vect[i];
	}
	
	return sqrt(result);
} 



int Ortogonal( float vect1[N], float vect2[N] ){
	
	return (Scalar(vect1,vect2) == 0);
}
void Projection( float vect1[N], float vect2[N], float vectres[N] ){
	float scalar=Scalar(vect1,vect2);
	float magnitude=Magnitude(vect2);
	float projeccio=scalar / magnitude;
	MultEscalar(vect2,vectres,projeccio);
}
float Infininorm( float M[N][N] ){
	float maxsum=0.0;
	for (int i=0; i<N; i++){
		float sumaFila=0.0;
		for (int j=0; j<N; j++){
			sumaFila+=fabs(M[i][j]);
		}
		if (sumaFila>maxsum){
			maxsum=sumaFila;
		}
	}
	
	return maxsum;
}
float Onenorm( float M[N][N] ){
	float maxsum=0.0;
	for (int j=0; j<N; j++){
		float sumaColumna=0.0;
		for (int i=0; i<N; i++){
			sumaColumna+=fabs(M[i][j]);
		}
		if (sumaColumna>maxsum){
			maxsum=sumaColumna;
		}
	}
	
	return maxsum;
}

float NormFrobenius( float M[N][N] ){
	float suma=0.0;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			suma+= M[i][j] * M[i][j];
		}
	}
	float frobenius=sqrt(suma);
	
	return frobenius;
}




int DiagonalDom( float M[N][N] ){
	for (int i=0; i<N; i++){
		float diagonal = fabs(M[i][i]);
	        float sumaFila = 0.0;
		
		for (int j=0; j<N; j++){
			if (j!=i){
				sumaFila+= fabs(M[i][j]);
			}
		}
		if (diagonal < sumaFila){
			return 0;
		}
	}
		return 1;
}
int Jacobi( float M[N][N] , float vect[N], float vectres[N], unsigned int iter ){
	if (!DiagonalDom(M)) {
	printf("La matriu M no és diagonal dominant, no es pot aplicar Jacobi\n");
	return 0;
		    }
	float temp[N];
	unsigned int k;
	for (k=0; k< iter;k++){
		for (int i = 0; i < N; i++) {
			temp[i]=vect[i];

			for (int j=0; j<N; j++){
				if (j!=i){
               			temp[i]-=M[i][j]*vectres[j];
				}
			
			
			}
			temp[i] /=M[i][i];
		}
		for (int i=0; i<N; i++){
			vectres[i]=temp[i];
		}
	}
	return 1;
}




int main(){
	InitData();
        //ComprovaciÓ A
	printf("V1 del 0 al 9 y del 256 al 265:\n"); 
        for (int i = 0; i < 10; i++) {
	   printf("%f ",V1[i]);
	}
printf("\n");

        for (int i=256; i<266; i++){
		printf("%f ",V1[i]);
	}
	printf("\n");

	printf("V2 del 0 al 9 y del 256 al 265:\n");
	for (int i = 0; i < 10; i++) { 
		 printf("%f ",V2[i]);
	}
	printf("\n");
	for (int i=256; i<266; i++){ 
		 printf("%f ",V2[i]);
	}
	printf("\n"); 
	printf("V3 del 0 al 9 y del 256 al 265:\n");
	for (int i = 0; i < 10; i++) {
		 printf("%f ",V3[i]);
	}
	printf("\n");
	 for (int i=256; i<266; i++){
	         printf("%f ",V3[i]);
	 } 
        printf("\n");
	//Comprovació B

        printf("Mat fila 0 i fila 100 del 0 al 9:\n");
	printf("Fila 0:\n");
	for (int j = 0; j < 10; j++) {
		  printf("%f ", Mat[0][j]);
	 }
	printf("\n");
        printf("Fila 100:\n");
	for (int j = 0; j < 10; j++) {
		  printf("%f ", Mat[100][j]);
			    }
	    printf("\n");
	

	//Comprovació C
	printf("MatDD fila 0 del 0 al 9 i fila 100 del 95 a 104:\n");
	printf("Fila 0:\n");
	for (int j = 0; j < 10; j++) {
		printf("%f ", MatDD[0][j]);
			    }
        printf("\n");
	printf("Fila 100:\n");
        for (int j = 95; j < 105; j++) {
                printf("%f ", MatDD[100][j]);
				    }
		    printf("\n");
        //Comprovació D
	printf("Infininorma de Mat = %f\n", Infininorm(Mat));
	printf("Norma ú de Mat = %f\n", Onenorm(Mat));
	printf("Norma de Frobenius de Mat = %f\n", NormFrobenius(Mat));
	printf("La matriu Mat %s diagonal dominant\n", DiagonalDom(Mat) ? "és" : "no és");
	printf("Infininorma de MatDD = %f\n", Infininorm(MatDD));
	printf("Norma ú de MatDD = %f\n", Onenorm(MatDD));
	printf("Norma de Frobenius de MatDD = %f\n", NormFrobenius(MatDD));
     	printf("La matriu MatDD %s diagonal dominant\n", DiagonalDom(MatDD) ? "és" : "no és");
	//Comprovació E
	float escalarV1V2 = Scalar(V1, V2);
	float escalarV1V3 = Scalar(V1, V3);
	float escalarV2V3 = Scalar(V2, V3);
	printf("Escalar <V1, V2> = %f\n", Scalar(V1, V2));
	printf("Escalar <V1, V3> = %f\n",  Scalar(V1, V3));
	printf("Escalar <V2, V3> = %f\n", Scalar(V2, V3));
	//Comprovació F
	printf("Magnitud V1,V2 i V3 = %f %f %f\n", Magnitude(V1), Magnitude(V2), Magnitude(V3));
	//Comprovació G
	if(Ortogonal(V1,V2)){
		printf("V1 i V2 són ortogonals\n");

	}else{
		printf("V1 i V2 no són ortogonals\n");
	}
	if (Ortogonal(V1,V3)){
		printf("V1 i V3 són ortogonals\n");
	}else{
		               
	       }	printf("V1 i V3 no són ortogonals\n");
	if(Ortogonal(V2,V3)){
		printf("V1 i V3 no són ortogonals\n");
	}else {
		printf("V1 i V3 no són ortogonals\n");
         }
	//comprovació H
	
	MultEscalar(V3,V1,2);
        printf("Elements 0 al 9 i 256 al 265 del resultat de multiplicar V3x2.0 són:\n");
        for (int i = 0; i < 10; i++) {
		printf("%f ",V1[i]);
	}
	printf("\n");
	
	for (int i = 256; i <= 265; i++) {
		printf("%f ", V1[i]);
	}
	printf("\n");
        //comprovació I
        Projection(V2,V3,V1);
	printf("Els elements 0 a 9 del resultat de la projecció de V2 sobre V3 són:\n");
	for (int i = 0; i < 10; i++) {
		printf("%f ", V1[i]);
	}
	printf("\n");
	Projection(V1,V2,V1);
	printf("Els elements 0 a 9 del resultat de la projecció de V1 sobre V2 són:\n");
	for (int i = 0; i < 10; i++) {
		printf("%f ", V1[i]);
	}
	printf("\n");
       //comprovació J

        Jacobi(MatDD,V3,V4,1);
	printf("Els elements 0 a 9 de la solució (1 iter) del sistema d'equacions són:\n");
	for (int i = 0; i < 10; i++) {
		 printf("%f ", V4[i]);
			     }
	printf("\n");
	Jacobi(MatDD,V3,V4,1000);
	printf("Els elements 0 a 9 de la solució (1000 iter) del sistema d'equacions són:\n");
        for (int i = 0; i < 10; i++) { 
		printf("%f ", V4[i]);
	
		    }
	printf("\n");
        Jacobi(Mat,V3,V4,1000);
        return 0;
}




