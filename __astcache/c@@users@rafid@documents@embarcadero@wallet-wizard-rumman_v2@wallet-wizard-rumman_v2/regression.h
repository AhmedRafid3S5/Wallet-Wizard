//---------------------------------------------------------------------------

#ifndef RegressionH
#define RegressionH
#include<vector>
#include<algorithm>
using namespace std;
//---------------------------------------------------------------------------
class regression {

	private:
	// Dynamic array which is going
	// to contain all (i-th x)
	vector<float> x;

	// Dynamic array which is going
	// to contain all (i-th y)
	vector<float> y;

	// Store the coefficient/slope in
	// the best fitting line
	float coeff;

	// Store the constant term in
	// the best fitting line
	float constTerm;

	// Contains sum of product of
	// all (i-th x) and (i-th y)
	float sum_xy;

    // Contains sum of all (i-th x)
	float sum_x;

    // Contains sum of all (i-th y)
    float sum_y;

    // Contains sum of square of
    // all (i-th x)
    float sum_x_square;

	// Contains sum of square of
    // all (i-th y)
    float sum_y_square;

public:
	// Constructor to provide the default
    // values to all the terms in the
    // object of class regression
    regression()
    {
		coeff = 0;
        constTerm = 0;
        sum_y = 0;
        sum_y_square = 0;
        sum_x_square = 0;
		sum_x = 0;
        sum_xy = 0;
    }

    // Function that calculate the coefficient/
	// slope of the best fitting line
    void calculateCoefficient()
    {
		float N = x.size();
        float numerator
			= (N * sum_xy - sum_x * sum_y);
        float denominator
            = (N * sum_x_square - sum_x * sum_x);
        coeff = numerator / denominator;
    }

    // Member function that will calculate
    // the constant term of the best
    // fitting line
    void calculateConstantTerm()
	{
        float N = x.size();
		/*float numerator
            = (sum_y * sum_x_square - sum_x * sum_xy);
        float denominator
			= (N * sum_x_square - sum_x * sum_x);
		constTerm = numerator / denominator;   */

		float b = coefficient();
		float avg_y =   sum_y / N;
		float avg_x = sum_x / N;

		constTerm = avg_y - b*avg_x;


    }

    // Function that return the number
	// of entries (xi, yi) in the data set
    int sizeOfData()
    {
        return x.size();
    }

    // Function that return the coefficient/
    // slope of the best fitting line
    float coefficient()
    {
		if (coeff == 0)
            calculateCoefficient();
        return coeff;
    }

	// Function that return the constant
    // term of the best fitting line
    float constant()
    {
        if (constTerm == 0)
			calculateConstantTerm();
        return constTerm;
    }



    // Function to take input from the dataset
	void takeInput(vector<float> depend, vector<float> independ)
    {
		for (int i = 0; i < independ.size(); i++) {
			// In a csv file all the values of
            // xi and yi are separated by commas
            char comma;
			float xi = independ[i];
			float yi = depend[i];

            sum_xy += xi * yi;
            sum_x += xi;
            sum_y += yi;
            sum_x_square += xi * xi;
			sum_y_square += yi * yi;
            x.push_back(xi);
            y.push_back(yi);
        }
    }

	//flush the x and y vectors
	void clear_vectors()
	{
		x.clear();
		y.clear();
    }

    // Function to predict the value
    // corresponding to some input
	float predict(float x)
    {
        return coeff * x + constTerm;
    }

	// Function that returns overall
    // sum of square of errors
    float errorSquare()
    {
        float ans = 0;
		for (int i = 0;
             i < x.size(); i++) {
            ans += ((predict(x[i]) - y[i])
                    * (predict(x[i]) - y[i]));
        }
		return ans;
    }

    // Functions that return the error
    // i.e the difference between the
	// actual value and value predicted
    // by our model
    float errorIn(float num)
    {
        for (int i = 0;
			 i < x.size(); i++) {
            if (num == x[i]) {
                return (y[i] - predict(x[i]));
            }
        }
		return 0;
	}

	float get_max_X()
	{
		float max = 0;
		for(int i=0;i<x.size();i++)
		{
		  if( x[i] > max)
			max = x[i];
		}

		return max;
	}

	float get_min_X()
     {
		float min = INT64_MAX;
		for(int i=0;i<x.size();i++)
		{
		  if( x[i] < min)
			min = x[i];
		}

		return min;
	}
};
#endif
