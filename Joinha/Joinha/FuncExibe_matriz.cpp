void FuncExibe_matriz(int matriz[][], int lin, int col)
{




    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<matriz[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
