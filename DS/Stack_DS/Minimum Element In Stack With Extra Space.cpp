/*

Complexity Analysis :

Time Complexity: O(1). All operation take constant time so time complexity will be O(1).

Space Complexity: O(N). N size stack used for keeping  track of min element.

*/

stack<int>s;
stack<int>support;

void push(int a)
{
    s.push(a);

    if (support.empty() || a <= support.top()) {
        support.push(a);
    }
}

int pop()
{
    int answer = s.top();

    if (answer == support.top()) {
        support.pop();
        s.pop();
        return answer;
    }

    s.pop();
    return answer;
}

int getMin()
{
    if (s.size() == 0) {
        return -1;
    }

    return support.top();
}