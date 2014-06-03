import java.io.FileOutputStream;

public class Optimize {	
	public static void main(String[] args) throws Exception {
		new File("simpler.txt").createNewFile();
		FileOutputStream fos = new FileOutputStream("simpler.txt");
		
		for (int l = 2; l <= 6; l++) {
			int[] m = new int[l];
			boolean c;
			int[] o = {0, 1};
			do {	
				for (int i : m) {
					
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