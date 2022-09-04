void zigzag_order(Node* root)
{
    if(root == NULL) return ;
    stack <Node*> currlevel;
    stack <NOde*> nextlevel;
    bool lefttoright = true ;
    currlevel.push(root);
    while (!currlevel.empty())
    {
        Node* temp = currlevel.top();
        currlevel.pop();

        if (temp)
        {
            cout << temp-> data << " ";

        if (lefttoright )
        {
            if (temp -> left )
            {
                nextlevel.push(temp -> left);
            }
            if (temp -> right )
            {
                nextlevel.push(temp->right);
            }
        }
        else
        {
            if (temp -> right )
            {
               nextlevel.push(temp -> right );
            }
            if (temp-> left )
            {
                nextlevel.push(temp->left);
            }
         }
       }
       if (currlevel.empty())
       {
           lefttoright =!lefttoright;
           swap(currlevel, nextlevel);
       }
    }
}
