package programming.baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1027_고층건물 {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine().trim());
		int[] arr = new int[N];
		int[] cnt = new int[N];
		double gradient1, gradient2;
		int maxCnt = 0;
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken().trim());
		}
		// 오른쪽으로 진행(오른쪽은 기울기가 이전보다 커야 볼 수 있음)
		for(int i = 0; i < N; i++) {
			gradient1 = -1e9; // 최소 기울기
			for(int j = i + 1;j < N; j++) {
				gradient2 = (double)(arr[j]-arr[i])/(j-i);
				if(gradient1 < gradient2) { // 최소 기울기보다 기울기가 크면 볼 수 있는 건물
					gradient1 = gradient2; // 최소 기울기 변경
					++cnt[j]; // 서로가 볼 수 있으므로 양쪽의 cnt를 증가
					++cnt[i];
				}
			}
		}
		// 최대 건물 수 계산
		for(int i = 0; i < N; i++) {
			maxCnt = maxCnt < cnt[i] ? cnt[i] : maxCnt;
		}
		System.out.println(maxCnt);
	}
}
