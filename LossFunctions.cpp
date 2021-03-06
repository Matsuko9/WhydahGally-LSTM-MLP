#include "LossFunctions.h"

namespace WhydahGally
{
	namespace Maths
	{
		//Simple loss function.
		std::vector<float> lossFunctSimple(const std::vector<float>& x, const std::vector<float>& y)
		{
			return vectorsDifference(x, y);
		}

		std::vector<float> lossFunctSimple(const std::vector<std::vector<float>>& x, const std::vector<float>& y)
		{
			return matrixVectorDifference(x, y);
		}

		//Logarithmic loss function.
		std::vector<float> lossFunctLog(const std::vector<float>& x, const std::vector<float>& y)
		{
			std::vector<float> results;
			results.resize(x.size());

			for (int i = 0; i < x.size(); ++i)
			{
				results.at(i) = (-((y[i] * log(x[i])) + ((1 - y[i]) * log(1 - x[i])))) * sign(x[i] - y[i]);
			}

			return results;
		}

		std::vector<float> lossFunctLog(const std::vector<std::vector<float>>& x, const std::vector<float>& y)
		{
			std::vector<float> results;
			results.resize(x.size());

			for (int i = 0; i < x.size(); ++i)
			{
				results.at(i) = (-((y[i] * log(x[i][0])) + ((1 - y[i]) * log(1 - x[i][0])))) * sign(x[i][0] - y[i]);
			}

			return results;
		}

		//Cubic logarithmic loss function.
		std::vector<float> lossFunctLogPow3(const std::vector<float>& x, const std::vector<float>& y)
		{
			std::vector<float> results;
			results.resize(x.size());

			for (int i = 0; i < x.size(); ++i)
			{
				results.at(i) = pow((-((y[i] * log(x[i])) + ((1 - y[i]) * log(1 - x[i])))) * sign(x[i] - y[i]), 3);
			}

			return results;
		}

		std::vector<float> lossFunctLogPow3(const std::vector<std::vector<float>>& x, const std::vector<float>& y)
		{
			std::vector<float> results;
			results.resize(x.size());

			for (int i = 0; i < x.size(); ++i)
			{
				results.at(i) = pow((-((y[i] * log(x[i][0])) + ((1 - y[i]) * log(1 - x[i][0])))) * sign(x[i][0] - y[i]), 3);
			}

			return results;
		}

		//Cubic loss function.
		std::vector<float> lossFunctPow3(const std::vector<float>& x, const std::vector<float>& y)
		{
			std::vector<float> results;
			results.resize(x.size());

			for (int i = 0; i < x.size(); ++i)
			{
				results.at(i) = pow(x[i] - y[i], 3);
			}

			return results;
		}

		std::vector<float> lossFunctPow3(const std::vector<std::vector<float>>& x, const std::vector<float>& y)
		{
			std::vector<float> results;
			results.resize(x.size());

			for (int i = 0; i < x.size(); ++i)
			{
				results.at(i) = pow(x[i][0] - y[i], 3);
			}

			return results;
		}

		//Cubic plus cubic logarithmic loss function.
		std::vector<float> lossFunctPow3PLogPow3(const std::vector<float>& x, const std::vector<float>& y)
		{
			std::vector<float> results;
			results.resize(x.size());

			for (int i = 0; i < x.size(); ++i)
			{
				results.at(i) = pow(x[i] - y[i], 3) + pow((-((y[i] * log(x[i])) + ((1 - y[i]) * log(1 - x[i])))) * sign(x[i] - y[i]), 3);
			}

			return results;
		}

		std::vector<float> lossFunctPow3PLogPow3(const std::vector<std::vector<float>>& x, const std::vector<float>& y)
		{
			std::vector<float> results;
			results.resize(x.size());

			for (int i = 0; i < x.size(); ++i)
			{
				results.at(i) = pow(x[i][0] - y[i], 3) + pow((-((y[i] * log(x[i][0])) + ((1 - y[i]) * log(1 - x[i][0])))) * sign(x[i][0] - y[i]), 3);
			}

			return results;
		}
	}
}





