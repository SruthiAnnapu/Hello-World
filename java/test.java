
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class RocketStages {
	static final int N = 11000;
	static final double G = 9.8;
	static double A[] = new double[N + 100];

	static int to_i(String s) {
		return Integer.valueOf(s);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		String stg = in.readLine();
		while (stg != null && !stg.isEmpty()) {
			int i, j;
			double neginf = -1.0 / 0;
			for (i = 1; i < N; i++) {
				A[i] = neginf;
			}
			A[0] = 0;
			int stages = to_i(stg);
			for (i = 0; i < stages; i++) {
				String[] vs = in.readLine().split(" ");
				int ms = to_i(vs[0]), mf = to_i(vs[1]), th = to_i(vs[2]), fc = to_i(vs[3]);
				for (j = N; j >= 0; j--) {
					int newm = j + ms;
					int totm = newm + mf;
					if (totm > 10000)
						continue;
					if (th / totm < G)
						continue;
					double time = 1.0 * mf / fc;
					double acc = th * (Math.log(newm + mf) - Math.log(newm)) / fc - time * G;
					acc = acc + A[j];
					if (acc <= A[newm + mf])
						continue;
					A[newm + mf] = acc;
				}
			}
			double mx = 0;
			for (i = 0; i < N; i++) {
				if (A[i] > mx)
					mx = A[i];
			}
			out.write(String.format("%.0f\n", mx));
			stg = in.readLine();
		}
		out.close();
	}
}