int maxPathSum(struct TreeNode* root);
int maxPathComparando(struct TreeNode *root, int maiorCaminho, int *max);

int main(){
    struct TreeNode *root;
    Inicializar(&root);
    Inserir(&root, 9);
    Inserir(&root, 10);
    Inserir(&root, -3);
    Inserir(&root, 4);
    Inserir(&root, 1);
    Inserir(&root, -6);

    int maxpath;
    maxpath = maxPathSum(root);
    printf("%d", maxpath);

    Liberar(&root);
    return 0;
}

int maxPathSum(struct TreeNode* root) {
    int *max = malloc(sizeof(int));
    *max = -100000;

    int retorno;
    maxPathComparando(root, 0, max);
    retorno = *max;

    free(max);
    return retorno;
}

int maxPathComparando(struct TreeNode *root, int maiorCaminho, int *max){
    int esq = 0, dir = 0, caminhoEsq = 0, caminhoDir = 0, caminhoTotal = 0;

    if( root == NULL ){
        return 0;
    }

    esq = maxPathComparando(root->left, maiorCaminho, max);
    dir = maxPathComparando(root->right, maiorCaminho, max);
    
    caminhoEsq = esq + root->val;
    caminhoDir = dir + root->val;
    caminhoTotal = esq + dir + root->val;


    if(caminhoEsq > root->val && caminhoEsq > caminhoDir){
        maiorCaminho = caminhoEsq;
    } else if(caminhoDir > root->val && caminhoDir > caminhoEsq){
        maiorCaminho = caminhoDir;
    } else {
        maiorCaminho = root->val;
    }

    if(caminhoTotal > *max){
        *max = caminhoTotal;
    }

    if(caminhoDir > *max){
        *max = caminhoDir;
    }

    if(caminhoEsq > *max){
        *max = caminhoEsq;
    }

    if(root->val > *max){
        *max = root->val;
    }

    return maiorCaminho;
}