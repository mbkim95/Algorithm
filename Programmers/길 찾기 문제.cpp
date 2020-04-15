#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pre, post;

struct Node {
	int x, y, idx;
	Node* left = NULL;
	Node* right = NULL;
};

bool cmp(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
	return a.first.second == b.first.second ? a.first.first < b.first.first : a.first.second > b.first.second;
}

// 트리에 노드를 삽입하는 함수
void insertNode(Node* root, int x, int y, int idx) {
	// 트리를 순회하면서 x값 비교를 하기 위한 기준노드
	Node* tmp = root;
	while (true) {
		if (tmp->x > x) {
			if (tmp->left != NULL)
				tmp = tmp->left;
			else {
				Node* newNode = new Node();
				newNode->x = x;
				newNode->y = y;
				newNode->idx = idx;
				tmp->left = newNode;
				break;
			}
		}
		else if (tmp->x < x) {
			if (tmp->right != NULL)
				tmp = tmp->right;
			else {
				Node* newNode = new Node();
				newNode->x = x;
				newNode->y = y;
				newNode->idx = idx;
				tmp->right = newNode;
				break;
			}
		}
	}
}

void preOrder(Node* cur) {
	pre.push_back(cur->idx);
	if (cur->left != NULL) preOrder(cur->left);
	if (cur->right != NULL) preOrder(cur->right);
}

void postOrder(Node* cur) {
	if (cur->left != NULL) postOrder(cur->left);
	if (cur->right != NULL) postOrder(cur->right);
	post.push_back(cur->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	vector<pair<pair<int, int>, int>> nodes;

	// nodeinfo에서 idx값도 포함하여 nodes 배열에 저장
	for (int i = 0; i < nodeinfo.size(); i++)
		nodes.push_back({ {nodeinfo[i][0], nodeinfo[i][1]}, i + 1 });

	sort(nodes.begin(), nodes.end(), cmp);

	// nodes[0]은 루트 노드
	Node* root = new Node();
	root->x = nodes[0].first.first;
	root->y = nodes[0].first.second;
	root->idx = nodes[0].second;

	// nodes[1]부터 트리에 노드를 삽입
	for (int i = 1; i < nodes.size(); i++)
		insertNode(root, nodes[i].first.first, nodes[i].first.second, nodes[i].second);
	preOrder(root);
	postOrder(root);
	answer.push_back(pre);
	answer.push_back(post);
	return answer;
}