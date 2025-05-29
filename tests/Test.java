package tests;

import solutions.Solution;
import java.util.*;

public class Test {
    public static void main(String[] args) {
        int passed = 0;
        int total = 0;

        List<TestCase> testCases = Arrays.asList(
            new TestCase(new int[]{4, 2, 1, 3}, Arrays.asList(Arrays.asList(1, 2), Arrays.asList(2, 3), Arrays.asList(3, 4))),
            new TestCase(new int[]{1, 3, 6, 10, 15}, Arrays.asList(Arrays.asList(1, 3))),
            new TestCase(new int[]{3, 8, -10, 23, 19, -4, -14, 27}, Arrays.asList(Arrays.asList(-14, -10), Arrays.asList(19, 23), Arrays.asList(23, 27))),
            new TestCase(new int[]{1, 2}, Arrays.asList(Arrays.asList(1, 2))),
            new TestCase(new int[]{1000000, -1000000}, Arrays.asList(Arrays.asList(-1000000, 1000000))),
            new TestCase(new int[]{5, 4, 3, 2}, Arrays.asList(Arrays.asList(2, 3), Arrays.asList(3, 4), Arrays.asList(4, 5))),
            new TestCase(new int[]{-1, -2, -3, -4}, Arrays.asList(Arrays.asList(-4, -3), Arrays.asList(-3, -2), Arrays.asList(-2, -1))),
            new TestCase(new int[]{0, 0, 0, 0}, Arrays.asList(Arrays.asList(0, 0), Arrays.asList(0, 0), Arrays.asList(0, 0))),
            new TestCase(new int[]{50000, -50000}, Arrays.asList(Arrays.asList(-50000, 50000))),
            new TestCase(generateRangeArray(-50000, 50000), generateExpectedForRange(-50000, 50000))
        );

        Solution sol = new Solution();

        for (TestCase tc : testCases) {
            total++;
            List<List<Integer>> actual = sol.minimumAbsDifference(tc.input);
            if (isEqual(actual, tc.expected)) {
                System.out.println("✔️ Test " + total + " passed.");
                passed++;
            } else {
                System.out.println("❌ Test " + total + " failed.");
                System.out.println("Input: " + Arrays.toString(tc.input));
                System.out.println("Expected: " + tc.expected);
                System.out.println("Actual: " + actual);
            }
        }

        System.out.println("\nPassed: " + passed + " / " + total + " test cases.");
    }

    static class TestCase {
        int[] input;
        List<List<Integer>> expected;

        TestCase(int[] input, List<List<Integer>> expected) {
            this.input = input;
            this.expected = expected;
        }
    }

    static boolean isEqual(List<List<Integer>> a, List<List<Integer>> b) {
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); i++) {
            if (!a.get(i).equals(b.get(i))) return false;
        }
        return true;
    }

    static int[] generateRangeArray(int start, int end) {
        int[] arr = new int[end - start + 1];
        for (int i = start; i <= end; i++) {
            arr[i - start] = i;
        }
        return arr;
    }

    static List<List<Integer>> generateExpectedForRange(int start, int end) {
        List<List<Integer>> res = new ArrayList<>();
        for (int i = start; i < end; i++) {
            res.add(Arrays.asList(i, i + 1));
        }
        return res;
    }
}
