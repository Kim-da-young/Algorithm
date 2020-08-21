package programming.baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class boj_2579_계단오르기 {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine().trim());
		int[] arr = new int[N];
		int[] dp = new int[N];
		if(N >= 1) {
			arr[0] = Integer.parseInt(br.readLine().trim());
			dp[0] = arr[0];
		}
		if(N >= 2) {
			arr[1] = Integer.parseInt(br.readLine().trim());
			dp[1] = dp[0] + arr[1];
		}
		if(N >= 3) {
			arr[2] = Integer.parseInt(br.readLine().trim());
			dp[2] = Math.max(arr[0]+arr[2], arr[1]+arr[2]);
		}
		for(int i = 3; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine().trim());
			dp[i] = arr[i];
			dp[i] += Math.max(dp[i-3] + arr[i-1], dp[i-2]);
		}
		System.out.println(dp[N-1]);
	}
}
