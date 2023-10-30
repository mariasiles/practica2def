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
		printf("%f ",vectres[i]);
	}
}

float Scalar( float vect1[N], float vect2[N] ){
	float resultat=0.0;
	for (int i=0; i<N; i++){
		
		resultat+= vect1[i] * vect2[i];
	}
	printf("%f",resultat);
	return resultat;
}

float Magnitude( float vect[N] ){
	int i;
	float result=0.0;
	for (i=0; i<N; i++){
		result+=vect[i]*vect[i];
	}
	printf("%f",sqrt(result));
	return sqrt(result);
} 



int Ortogonal( float vect1[N], float vect2[N] ){
	printf("%f",Scalar(vect1,vect2));
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
	printf("%f",maxsum);
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
	printf("%f",maxsum);
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
	printf("%f",frobenius);
	return frobenius;
}






int main(){
	InitData();

	
	
	return 0;
}



