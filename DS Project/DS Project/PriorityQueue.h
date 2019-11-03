#pragma once
#include <iostream>

class PriorityQueue
{

	void push(Node** fr, Node** rr, int n, int p)
	{
		Node* news = (Node*)malloc(sizeof(Node));
		news->info = n;
		news->priority = p;

		if (*fr == NULL)
		{
			*fr = news;
			*rr = news;
			news->next = NULL;
		}
		else {
			if (p <= (*fr)->priority)
			{
				news->next = *fr;
				(*fr)->prev = news->next;
				*fr = news;
			}
			else if (p > (*rr)->priority)
			{
				news->next = NULL;
				(*rr)->next = news;
				news->prev = (*rr)->next;
				*rr = news;
			}
			else {
				Node* start = (*fr)->next;
				while (start->priority > p)
				{
					start = start->next;
				}
				(start->prev)->next = news;
				news->next = start->prev;
				news->prev = (start->prev)->next;
				start->prev = news->next;
			}
		}
	}

	int peek(Node* fr)
	{
		return fr->info;
	}

	bool isEmpty(Node* fr)
	{
		return (fr == NULL);
	}


	int pop(Node** fr, Node** rr)
	{
		Node* temp = *fr;
		int res = temp->info;
		(*fr) = (*fr)->next;
		free(temp);
		if (*fr == NULL)
		{
			*rr = NULL;
		}
		return res;
	}

};

// Priority Queue DS using doubly linked list
class Node
{
public:
	int info;
	int priority;
	Node* prev;
	Node* next;
};


