[🔝](../README.md)

# 22/04/2024 - Aula 008

```c
void Puch()
{
    if (topo === NULL)
    {
        topo = (no*)malloc(sizeof(no));
		topo->next=NULL;
		topo->back=NULL;
		auxiliar = topo;
		c++;
		Enterdata();
    } else {
		if(c>10)
		{
			printf("\n stack overdlow...");
			system("\n pause");
		} else {
			topo=(no*)malloc(sizeof(no));
			auxiliar->next = topo;
			topo->back=auxiliar;
			topo->next=Null;
			c++;
			Enterdata();
		}
	}
}
void main()
{
	topo=Null;
	auxiliar=Null;
}
```


