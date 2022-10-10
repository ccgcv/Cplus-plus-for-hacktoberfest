class Maxheap
{
    public :
    int _size = 0;
    vector<int>v{-1};

    int parent_node(int index)
    {
        return index/2;
    }

    int left_child(int index)
    {
        return index*2;
    }

    int right_child(int index)
    {
        return (index*2) + 1;
    }

    void move_up(int index)
    {
        if(index<=1)
        {
            return;
        }

        int parent = parent_node(index);
        if(v[index]>v[parent]) //should go up
        {
            swap(v[index],v[parent]);
            move_up(parent);
        }
        return;
    }

    void move_down(int index)
    {
        int left_index  = left_child(index);
        int right_index = right_child(index);

        int left  = INT_MIN;
        int right = INT_MIN;

        if(left_index<=_size)
        {
            left = v[left_index];
        }

        if(right_index<=_size)
        {
            right = v[right_index];
        }

        if(v[index]<v[left_index] && left>right)
        {
            swap(v[index],v[left_index]);
            move_down(left_index);
        }
        if(v[index]<v[right_index] && left<right)
        {
            swap(v[index],v[right_index]);
            move_down(right_index);
        }

        return;
    }   

    void insert(int val)
    {
        v.push_back(val);
        _size++;
        move_up(_size);
    }

    int extract()
    {
        if(_size==0)
        {
            return -1;
        }

        int largest = v[1];

        v[1] = v[_size];
        _size--;

        move_down(1);

        return largest;
    }

    void display()
    {
        cout<<"Displaying Max Heap"<<"\n";
        for(int i=1;i<=_size;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<"\n"<<"\n";
        return;
    }

};

int main()
{
    Maxheap* heap = new Maxheap();
    
    heap->insert(100);
    heap->insert(20);
    heap->insert(10);
    heap->insert(90);
    heap->insert(80);
    heap->insert(40);
    heap->insert(50);
    heap->display();

    heap->extract();
    heap->display();

    return 0;
}
