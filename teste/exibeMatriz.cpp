
void exibeMatriz(int matriz[lin][col])
{
    cout<<"\n\n    ";
    for(int m=0;m<col;m++)
    {
        cout<<m<<" ";
    }

    cout<<"\n    ";
    for(int x=0;x<col;x++)
    {
        cout<<"| ";
    }

    cout<<endl;

    for(int i=0;i<lin;i++)
    {
        cout<<i<<" - ";
        for(int j=0;j<col;j++)
        {
            cout<<matriz[i][j]<<" ";
        }
        cout<<"\n";
    }
}
