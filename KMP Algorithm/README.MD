<h1><b>Introfuction KMP Algorithm</b></h1>

<h3><i>We need to compare all m indexces at each index in the given string</i></h3> 

<hr>

![Pattern-Searching-2-1](https://user-images.githubusercontent.com/99535791/175977281-3fbe443a-158a-4cc7-b96e-0aaba6b75dc3.png)

<hr>

<h1><b>Intuition</b></h1>

<h3><i>Here we make use of the common prefix concepts. Whenever we find that prefixes are common, then we make a note of them so that those common prefixes are not 
compared again in subsequent searches.</i></h3>

<h1><b>Approach</b></h1>

<h3><i>We make a pi Table here so keep track of common prefixes. We have to shift indices of the pattern by 1 to make the process easier, ie, the pattern begins 
at index 1 and we always compare pattern[j+1] with string[i] and not the jth index of the pattern. Then the only change is that whenever there is a mismatch, 
then we go to the index pointed to by our pi table and do not stop the search. Like this, we keep on going to previous indices of the pi table on mismatch until there
is a mismatch or that j=0( refer to code for more understanding). So like this, when we find that j is m, we stop as we have found the pattern, else 
return -1 when i reaches n.</i></h3>

<h1><b>Complexity</b></h1>

<h3><i>O(m+n) where m and n are patterns and string lengths respectively.</i></h3>


