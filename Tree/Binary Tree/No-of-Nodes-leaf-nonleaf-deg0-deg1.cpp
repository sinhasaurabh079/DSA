// only functions

int Tree::Height(Node *p)
{
    int l = 0;
    int r = 0;

    if (p != nullptr)
    {
        l = Height(p->lchild);
        r = Height(p->rchild);
        if (l > r)
        {
            return l + 1;
        }
        else
        {
            return r + 1;
        }
    }
    return 0;
}

int Tree::Count(Node *p)
{
    int x;
    int y;
    if (p != nullptr)
    {
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int Tree::Sum(Node *p)
{
    int x;
    int y;
    if (p != nullptr)
    {
        x = Sum(p->lchild);
        y = Sum(p->rchild);
        return x + y + p->data;
    }
    return 0;
}

int Tree::deg2NodeCount(Node *p)
{
    int x;
    int y;
    if (p != nullptr)
    {
        x = deg2NodeCount(p->lchild);
        y = deg2NodeCount(p->rchild);
        // for this both left and right child should exist
        if (p->lchild && p->rchild)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int Tree::leafNodeCount(Node *p)
{
    int x;
    int y;
    if (p != nullptr)
    {
        x = leafNodeCount(p->lchild);
        y = leafNodeCount(p->rchild);
        // left and right child should be null
        if (p->lchild == nullptr && p->rchild == nullptr)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int Tree::deg1ordeg2NodeCount(Node *p)
{
    int x;
    int y;
    if (p != nullptr)
    {
        x = deg1ordeg2NodeCount(p->lchild);
        y = deg1ordeg2NodeCount(p->rchild);
        // either left exists or right exists
        if (p->lchild != nullptr || p->rchild != nullptr)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int Tree::deg1NodeCount(Node *p)
{
    int x;
    int y;
    if (p != nullptr)
    {
        x = deg1NodeCount(p->lchild);
        y = deg1NodeCount(p->rchild);
        // if left exist then right will not exist , vice versa
        if (p->lchild != nullptr ^ p->rchild != nullptr)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}