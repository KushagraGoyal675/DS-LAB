#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

int adj[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int numVertices;

void dfs(int vertex)
{
    visited[vertex] = 1;
    printf("%d ", vertex + 1);
    for (int i = 0; i < numVertices; i++)
    {
        if (adj[vertex][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    printf("ENTER THE NUMBER OF VERTICES: ");
    scanf("%d", &numVertices);
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (i != j)
            {
                printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0: ", i + 1,
                       j + 1);
                scanf("%d", &adj[i][j]);
            }
            else
            {
                adj[i][j] = 0;
            }
        }
    }

    printf("THE ADJACENCY MATRIX IS:\n");

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    char choice;
    do
    {
        for (int i = 0; i < numVertices; i++)
        {
            visited[i] = 0;
        }
        int sourceVertex;
        printf("ENTER THE SOURCE VERTEX: ");
        scanf("%d", &sourceVertex);
        printf("DFS Traversal starting from vertex %d:\n", sourceVertex);
        dfs(sourceVertex - 1);
        printf("\nDO U WANT TO CONTINUE (Y/N)? ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    return 0;
}