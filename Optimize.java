import java.io.*;

public class Optimize {
    public static void main(String[] args) throws Exception {
        new File("simpler.txt").createNewFile();
        FileOutputStream fos = new FileOutputStream("simpler.txt");
        final int[][] f = new int[][] {{-1, 2, 4, -1, 5, 1}, {5, -1, 0, 2, -1, 3}, {1, 3, -1, 4, 0, -1}};
        final char[] h = {'r', 'l', 'f'};
        for (int l = 2; l <= 12; l++) {
            int[] m = new int[l];
            boolean c;
            do {
                int[] o = {0, 1};
                for (int i : m) {
                    int v = (f[o[0] % 3][o[1]] + (i != 2 ? 0 : 3) + (o[0] < 3 ? 0 : 3)) % 6;
                    if (i == 2) {
                        o[0] = v;
                    } else {
                        o[1] = v;
                    }
                }
                l:
                for (int q = 0; q < l; q++) {
                    int[] n = new int[q];
                    boolean d;
                    do {
                        int[] p = {0, 1};
                        for (int i : n) {
                            int v = (f[p[0] % 3][p[1]] + (i != 2 ? 0 : 3) + (p[0] < 3 ? 0 : 3)) % 6;
                            if (i == 2) {
                                p[0] = v;
                            } else {
                                p[1] = v;
                            }
                        }
                        if (o[0] == p[0] && o[1] == p[1]) {
                            for (int i : m) {
                                fos.write(h[i]);
                            }
                            fos.write('\n');
                            for (int i : n) {
                                fos.write(h[i]);
                            }
                            fos.write('\n');
                            break l;
                        }
                        for (int i = 0; i < q; i++) {
                            if (n[i] == 2) {
                                n[i] = 0;
                            } else {
                                n[i]++;
                                break;
                            }
                        }
                        d = false;
                        for (int i = 0; i < q; i++) {
                            if (n[i] != 0) {
                                d = true;
                                break;
                            }
                        }
                    } while (d);
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
            } while (c);
        }
    }
}
