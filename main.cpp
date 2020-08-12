#include "functions.cpp"

int main()
{

	float A [SIZE][SIZE] =
	{{    3,    1,    -1,    0},
	{	  0,	7,	  -3,	 0},
	{	  0,   -3,	   9,   -2},
	{     0,    0,     4,   -10}};
	
	
	Matrix* matrixA = new Matrix(SIZE,SIZE, (float*) A, SIZE,SIZE);
	
	const int VECT_SIZE = matrixA->GetCol();	
	float vect_b [VECT_SIZE] = {3,	4, 4, -6};
		
	cout<<"******Matrix A******"<<endl;
	matrixA->print();
	cout<<endl;
	
	cout<<"******Vector b:****** "<<endl;
	print_vect(vect_b, VECT_SIZE);
	cout<<endl;
	
	
	cout<<"Norma Infty of matrix A is: "<<matrixA->NormaInfty()<<endl;
	cout<<"Norma infty of vector b is: "<<norma_inf_vect(vect_b, VECT_SIZE)<<endl;
	cout<<endl;
	
	//System A = b with gaussian reduction method
	float*system_result = NULL;
	system_result = SystemMatrix(matrixA, VECT_SIZE, vect_b);
	
	//print results
	cout<<"The solution of A=b linear system is:"<<endl;
	for (int i=0; i< matrixA->GetRow(); i++)
	{
		cout<<"x"<<i<<"= "<<system_result[i]<<endl;
	}
	cout<<endl;
	
	//prove correctness
	cout<<"A*solution = b if solution is correct"<<endl;
	float * verify = matrixA->Multiply(system_result, VECT_SIZE);
	print_vect(verify, VECT_SIZE);
	cout<<endl;
}
