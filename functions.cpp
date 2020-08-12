#include "header.h" 


// calculate infty norma of vector
float norma_inf_vect (float vector[], int size)
{
	float max = 0;
	
	for (int i=0; i<size; i++)
	{
		if (abs(vector[i]) > max)
		{
			max = abs(vector[i]);
		}
	}
	
	return max;
}

void print_vect(float vect[], int size)
{
	for (int i=0; i<size; i++)
	{
		cout<<vect[i]<<" ";
	}	
	cout<<endl;
}


//Solve linear equation using gaussian method 
float* SystemMatrix (Matrix* m, int vect_size, float* vect_b)
{
	if (m->GetRow() != vect_size)
	{
		cout<<"ERROR, matrix row and vectors size must be equal";
		return NULL;
	}
	
	int i,j,k;
	Matrix* res = new Matrix(vect_size ,vect_size);
    float c;
    float* x_res = new float[vect_size];
        
    //copy input matrix in result matrix
    for(int i=0; i<vect_size; i++)
    {
		for(int j=0; j<vect_size; j++)
		{	
			res->matrix[i][j] = m->matrix[i][j];
		}
	}
	
     
    res = res->AddColumn(vect_b, vect_size);
    
    /* Now finding the elements of diagonal matrix */
    for(j=0; j<m->GetRow(); j++)
    {
        for(i=0; i<m->GetRow(); i++)
        {
            if(i!=j)
            {
                c=res->matrix[i][j]/res->matrix[j][j];
                
                for(k=0; k<=m->GetCol(); k++)
                {
                    res->matrix[i][k]=res->matrix[i][k]-c*res->matrix[j][k];
                }
            }
        }
    }

    for(i=0; i<m->GetRow(); i++)
    {
        x_res[i] = (res->matrix[i][m->GetRow()])/(res->matrix[i][i]); 
    }
    
    return (float*)x_res;
}
