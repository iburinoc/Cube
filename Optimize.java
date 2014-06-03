import java.io.FileOutputStream;

public class Optimize {	
	public static void main(String[] args) throws Exception {
		new File("simpler.txt").createNewFile();
		FileOutputStream fos = new FileOutputStream("simpler.txt");
		final int[][] f = new int[][] {{{-1, 2, 4, -1, 5, 1}, {5, -1, 0, 2, -1, 3}, {1, 3, -1, 4, 0, -1}}};
		for (int l = 2; l <= 6; l++) {
			int[] m = new int[l];
			boolean c;
			int[] o = {0, 1};
			do {	
				for (int i : m) {			
					int v = (f[o[0] % 3][o[1]] + (i != 2 ? 0 : 3) + (o[0] < 3 ? 0 : 3)) % 6;					
					if (i == 0) {
						o[0] = v;
					} else {
						o[1] = v;
					}
				}
				for (int i = 0; i < l; i++) {
					if (m[i] == 2) {
						m[i] = 0;
					} else {
						m[i]++;
						break;
					}
				}		
				c = false;
				for (int i = 0; i < l; i++) {
					if (m[i] != 0) {
						c = true;
						break;
					}
				}
			} while (!c);
		}
	}
}