#include "test.h"

using BufferedReader = java::io::BufferedReader;
using BufferedWriter = java::io::BufferedWriter;
using IOException = java::io::IOException;
using InputStreamReader = java::io::InputStreamReader;
using OutputStreamWriter = java::io::OutputStreamWriter;
std::vector<double> RocketStages::A(N + 100);

int RocketStages::to_i(const std::wstring &s)
{
	return std::stoi(s);
}

void RocketStages::main(std::vector<std::wstring> &args)
{
	InputStreamReader tempVar(System::in);
	BufferedReader *in = new BufferedReader(&tempVar);
	OutputStreamWriter tempVar2(System::out);
	BufferedWriter *out = new BufferedWriter(&tempVar2);
	std::wstring stg = in->readLine();
	while (stg != L"" && !stg.isEmpty())
	{
		int i, j;
		double neginf = -1.0 / 0;
		for (i = 1; i < N; i++)
		{
			A[i] = neginf;
		}
		A[0] = 0;
		int stages = to_i(stg);
		for (i = 0; i < stages; i++)
		{
			std::vector<std::wstring> vs = in->readLine()->split(L" ");
			int ms = to_i(vs[0]), mf = to_i(vs[1]), th = to_i(vs[2]), fc = to_i(vs[3]);
			for (j = N; j >= 0; j--)
			{
				int newm = j + ms;
				int totm = newm + mf;
				if (totm > 10000)
				{
					continue;
				}
				if (th / totm < G)
				{
					continue;
				}
				double time = 1.0 * mf / fc;
				double acc = th * (std::log(newm + mf) - std::log(newm)) / fc - time * G;
				acc = acc + A[j];
				if (acc <= A[newm + mf])
				{
					continue;
				}
				A[newm + mf] = acc;
			}
		}
		double mx = 0;
		for (i = 0; i < N; i++)
		{
			if (A[i] > mx)
			{
				mx = A[i];
			}
		}
		out->write(std::wstring::format(L"%.0f\n", mx));
		stg = in->readLine();
	}
	out->close();

	delete out;
	delete in;
}
