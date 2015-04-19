import java.io.*;
import java.util.*;

public class plm {
    public static Scanner in;
    public static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
    in = new Scanner(new BufferedInputStream(new FileInputStream(new File(
        "input.txt"))));
    out = new PrintWriter(new BufferedOutputStream(new FileOutputStream(
        new File("output.txt"))));
    int nCases = in.nextInt();
    in.nextLine();
    for (int CASE = 1; CASE <= nCases; CASE++) {
        out.print("Case #" + CASE + ": ");
        solve();
    }
    out.close();
    System.err.println("Done");
    }

    static void solve() {
    in.nextInt();
    int X = in.nextInt();
    in.nextLine();
    String s = in.next();
    System.err.println(s.length());
    boolean found = false;

    char ans = '1';
    boolean negative = false;
    boolean found_i = false;
    boolean found_j = false;
    for (int i = 0; i < X; i++) {
        Object[] ret = eval(s, ans, negative, found_i, found_j);
        ans = (Character) ret[0];
        negative = (Boolean) ret[1];
        found_i = (Boolean) ret[2];
        found_j = (Boolean) ret[3];
    }
    if (negative && ans == '1' && found_i && found_j)
        found = true;
    if (found)
        out.println("YES");
    else
        out.println("NO");
    }

    static Object[] eval(String s, char ans, boolean negative, boolean found_i,
        boolean found_j) {
    for (int i = 0; i < s.length(); i++) {
        char c = s.charAt(i);
        negative = negative ^ sign(ans, c);
        ans = multiply(ans, c);
        if (ans == 'i' && !negative)
        found_i = true;
        if (found_i && ans == 'k' && !negative)
        found_j = true;
    }
    Object[] ret = new Object[] { ans, negative, found_i, found_j };
    return ret;
    }

    static char multiply(char a, char b) {
    if (a == '1')
        return b;
    if (b == '1')
        return a;
    if (a == b)
        return '1';
    switch (a) {
        case 'i':
        if (b == 'j')
            return 'k';
        if (b == 'k')
            return 'j';
        case 'j':
        if (b == 'i')
            return 'k';
        if (b == 'k')
            return 'i';
        case 'k':
        if (b == 'i')
            return 'j';
        if (b == 'j')
            return 'i';
    }
    return '0';
    }

    static boolean sign(char a, char b) {
    if (a == '1' || b == '1')
        return false;
    if (a == b)
        return true;
    if (a == 'i' && b == 'k' || a == 'j' && b == 'i' || a == 'k'
        && b == 'j')
        return true;
    return false;
    }
}
