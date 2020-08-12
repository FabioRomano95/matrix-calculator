#include <math.h>
#include <iostream>
#include <array>
#include <algorithm> 

using namespace std;

int const SIZE = 4;


class Matrix
{
	private:
	 int nRow;
	 int nCol;
	 
	public:
	 float** matrix;
 	
 	//create empty matrix
	Matrix(int row, int col)
	{
		nRow = row;
		nCol= col;
		matrix = new float*[row];
		
		for (int i=0; i<row; i++)
		{
			matrix[i] = new float[col];
		}
		
	 }
	
	//create matrix from 2d array 
	Matrix(int row, int col, float* m, int m_row, int m_col)
	{
		nRow = row;
		nCol= col;
		matrix = new float*[row];
		
		for (int i=0; i<row; i++)
		{
			matrix[i] = new float[col];
		}
		
		if (m != NULL)
		{
			for(int i=0; i<m_row; i++)
				for(int j=0; j<m_col; j++)		
					matrix[i][j] = *(m+i*m_col+j);	
		}
	}
	
	
	int GetRow()
	{
		return nRow;
	}
	
	int GetCol()
	{
		return nCol;
	}
	
	Matrix* AddColumn(float *newColumn, int size)
	{
		
		Matrix * res = new Matrix (nRow, nCol+1);
		
		for (int i=0; i<nRow; i++)
		{
			for (int j=0; j<nCol; j++)
			{
				res->matrix[i][j] = matrix[i][j];
				
				if(j == nCol-1)
				{
					res->matrix[i][j+1] = newColumn[i]; 
				}
			}
	
		}
				 
		return res;
	}
	
	
	//row-column multiply
	float* Multiply(float vector[], int size)
	{
		float* res = new float[size] {0};

		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)
			{
				res[i]= res[i] + (matrix[i][j] * vector[j]);
			}			
		}

		return res;
	}
	
	//infinity norm or uniform norm  
	float NormaInfty()
	{
		float max = 0;
		
		for (int i=0; i<GetRow(); i++)
		{
			float sum = 0;
			
			for (int j = 0; j<GetCol(); j++)
			{
				sum = sum + abs(matrix[i][j]);
			}
			
			if (sum > max)
			{
				max = sum;
			}
		}
		
	    return max;
	}
	
	
	void FreeMemory()
	{
		for(int i=0; i<nRow; i++)
		{
			free(matrix[i]);
		}
		
		free(matrix);
	}
	
	
	void print()
	{
		for(int i=0; i<nRow; i++)
		{
			for(int j=0; j<nCol; j++)
			{
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
};
