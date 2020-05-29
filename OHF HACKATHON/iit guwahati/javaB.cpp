import java.math.BigInteger;
import java.util.*;

public class StringsInStringsCached {
    //use arrays of CustomCharacter as strings/forms, use nulls when a index is not yet filled in
    enum CustomCharacter {
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
    };

    static HashMap<List<CustomCharacter>, BigInteger> cache;

    public static void main(String[] args) {
         Scanner scan = new Scanner(System.in);
        // System.out.print("Enter any number: ");

        // This method reads the number provided using keyboard
        // Long num = scan.nextInt();
        Long num = scan.nextLong();

        String sub= scan.next();
        String s2= sub.toUpperCase();
        List<CustomCharacter> string = customCharListWithNulls(num);
        List<CustomCharacter> substring = customCharListFromString(s2);

        cache = new HashMap<List<CustomCharacter>, BigInteger>();

        System.out.println(countPossibilities(string, substring));
    }

    static BigInteger countPossibilities(List<CustomCharacter> form, List<CustomCharacter> substring) {
        if(!cache.containsKey(form)){
            BigInteger possibilities = BigInteger.ZERO;
            //put our substring at any index in the form
            for (Long index = 0; index <= form.size() - substring.size(); index++) {
                //see if the substring fits at that index
                if (fits(form, substring, index)) {
                    //count the possibilities for filling in the prefix
                    List<CustomCharacter> prefix = copyOfRange(form, 0, index);
                    BigInteger.valueOf(CustomCharacter.values().length).pow(countNulls(prefix));
                    BigInteger.valueOf(countNulls(prefix));

                    BigInteger prefixPossibilities = BigInteger.valueOf(CustomCharacter.values().length).pow(countNulls(prefix));
                    //count the possibilities for filling in the suffix
                    List<CustomCharacter> suffix = copyOfRange(form, index+substring.size(), form.size());
                    BigInteger suffixPossibilities = BigInteger.valueOf(CustomCharacter.values().length).pow(countNulls(suffix));

                    //count the possibilities where we fill the prefix such that our index is not the first occurence of the substring anymore
                    //these need to be subtracted
                    List<CustomCharacter> reducedForm = copyOfRange(insert(form,substring,index), 0, index + substring.size() - 1);
                    BigInteger invalidPrefixPossibilities = countPossibilities(reducedForm, substring);

                    possibilities = possibilities.add((prefixPossibilities.subtract(invalidPrefixPossibilities)).multiply(suffixPossibilities));
                }

            }

            cache.put(form, possibilities);
        }
        return cache.get(form);
    }

    private static boolean fits(List<CustomCharacter> form, List<CustomCharacter> substring, Long index) {
        boolean result = true;
        for (Long subStrIndex = 0; subStrIndex < substring.size(); subStrIndex++) {
            if (!(form.get(index + subStrIndex) == null || form.get(index + subStrIndex) == substring.get(subStrIndex))) {
                result = false;
            }
        }
        return result;
    }

    private static Long countNulls(List<CustomCharacter> l) {
        Long result = 0;
        for (Long i = 0; i < l.size(); i++) {
            if (l.get(i) == null) {
                result++;
            }
        }
        return result;
    }

    private static List<CustomCharacter> insert(List<CustomCharacter> form, List<CustomCharacter> substring, Long index) {
        List<CustomCharacter> result = new ArrayList<CustomCharacter>(form);
        for (Long i = 0; i < substring.size(); i++) {
            result.set(index + i, substring.get(i));
        }
        return result;
    } 

    private static List<CustomCharacter> copyOfRange(List<CustomCharacter> l, Long from, Long to){
        List<CustomCharacter> result = new ArrayList<CustomCharacter>();
        for(Long i = from; i < to; i++){
            result.add(l.get(i));
        }
        return result;
    }

    private static List<CustomCharacter> customCharListWithNulls(Long size) {
        List<CustomCharacter> result = new ArrayList<CustomCharacter>();
        for(Long i = 0; i < size; i++){
            result.add(null);
        }
        return result;
    }

    private static List<CustomCharacter> customCharListFromString(String s) {
        List<CustomCharacter> result = new ArrayList<CustomCharacter>();
        for(char c : s.toCharArray()){
            result.add(CustomCharacter.valueOf(String.valueOf(c)));
        }

        return result;
    }
}