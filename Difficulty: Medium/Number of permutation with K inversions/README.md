<h2><a href="https://www.geeksforgeeks.org/problems/number-of-permutation-with-k-inversions5304/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article">Number of permutation with K inversions</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array, an inversion is defined as a pair a[i], a[j] such that a[i] &gt; a[j] and i &lt; j. Given two numbers N and K, the task is to find the count of the number of permutations of first N numbers have exactly K inversion.</span></p>
<p><span style="font-size: 18px;"><strong>Note</strong>: Answer can be large, output answer modulo 10<sup>9</sup> + 7</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: N = 3, K = 1
<strong>Output:</strong> 2</span>
<span style="font-size: 18px;"><strong>Explanation</strong>: Total Permutation of first 
3 numbers, 123, 132, 213, 231, 312, 321
Permutation with 1 inversion : 132 and 213</span></pre>
<div><span style="font-size: 18px;"><strong>Example 2:</strong></span></div>
<pre><span style="font-size: 18px;"><strong>Input</strong>: N = 3, K = 3
<strong>Output:</strong> 0</span>
<span style="font-size: 18px;"><strong>Explanation</strong>: No such permutation</span></pre>
<div><br><span style="font-size: 18px;"><strong>Your Task:&nbsp;&nbsp;</strong><br>You don't need to read input or print anything. Complete the function <strong><code>numberOfPermWithKInversion</code>()&nbsp;</strong>which takes <strong>N</strong> and <strong>K </strong>as input parameters and returns the integer value<br><br><strong>Expected Time Complexity:</strong> O(<strong>N*K</strong>)<br><strong>Expected Auxiliary Space:</strong> O(<strong>N*K</strong>)<br><br><strong>Constraints:</strong><br>1 ≤ <strong>N*K</strong> ≤ 10<sup>6</sup></span></div>
<p>&nbsp;</p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;