#pragma once
class Lab3
{
private:
	struct Node
	{
		unsigned int _key;
		unsigned int _lvl;
		Node* _right;
		Node* _left;
	};

	Node* _root;

	void Push(Node* node, const unsigned int &item, const unsigned int lvl);
	void NLR(Node* node) const;
	unsigned int GetNodeOnLvl(Node* node, const unsigned int &lvl, unsigned int currentLvl) const;

public:
	Lab3();

	void Push(const unsigned int &item);
	void Print() const;
	void NodesOnLvl(const unsigned int &lvl) const;

	~Lab3();
};

