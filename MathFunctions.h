#pragma once

#include <math.h>
#include <vector>
#include <iostream>

#include "Definitions.h"
#include "Matrix.h"

namespace WhydahGally
{
	namespace Maths
	{
		//Maths functions.
		template<typename T> T sigmoid(const T& x)
		{
			return 1 / (1 + exp(-x));
		}

		template<typename T> T derivativeSigmoid(const T& x)
		{
			return x * (1 - x);
		}

		template<typename T> T sign(const T& x)
		{
			if (x >= 0)
			{
				return 1.0f;
			}
			else
			{
				return -1.0f;
			}
		}

		float mean(const std::vector<float>& x);
		float mean(const std::vector<std::vector<float>>& x);
		template<typename T> T mean(const Matrix<T>& x)
		{
			T sum = (T)0.0f;

			for (int i = 0; i < (x.rows_ * x.cols_); ++i)
			{
				sum += x.elements_[i];
			}

			return sum / ((T)(x.rows_ * x.cols_));
		}

		float sum(const std::vector<float>& x);
		template<typename T> T sum(const Matrix<T>& x)
		{
			T sum = (T)0.0f;

			for (int i = 0; i < (x.rows_ * x.cols_); ++i)
			{
				sum += x.elements_[i];
			}

			return sum;
		}

		template<typename T> T abs(const T& x)
		{
			if (x >= 0)
			{
				return x;
			}
			else
			{
				return -x;
			}
		}

		std::vector<float> abs(const std::vector<float>& x);
		std::vector<std::vector<float>> abs(const std::vector<std::vector<float>>& x);

		//Pseudo-random number generation with normal distribution using the Box-Muller method. 
		template<typename T> T randNormalDistrib(const T& mean, const T& stdDev)
		{
			static bool nBool = 0;
			static float n = 0.0f;

			if (!nBool)
			{
				float x;
				float y;
				float z;

				do
				{
					x = 2.0f * rand() / RAND_MAX - 1.0f;
					y = 2.0f * rand() / RAND_MAX - 1.0f;
					z = pow(x, 2) + pow(y, 2);
				} while (z > 1.0f || z == 0.0f);
				{
					float w = sqrt(-2.0f * log(z) / z);
					float m = x * w;

					n = y * w;

					float result = m * stdDev + mean;
					nBool = 1;

					return result;
				}
			}
			else
			{
				nBool = 0;

				return (T)(n * stdDev + mean);
			}
		}
	}
}

