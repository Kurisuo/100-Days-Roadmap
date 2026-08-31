__global__ void vecAdd(float* A, float* B, float* C){


}

//truple chevron notation for kernal launch
int main(){
    //Grid dimension - Thread Block Dimension
    vecAdd<<<1, 256>>>(A, B, C);
} //This block launches a single thread block containing 256 threads and all execute the same kernel code


int main(){
    dim3 grid(16, 16);
    dim3 block(8, 8);
    MatAdd<<<grid, block>>>(A, B,C);
} //dim3 is a CUDA type used for 2 or 3-dimensional grids/blocks, 


/*

threadIdx : gives the index of the thread within its block
blockDim : gives Block Dimension of thread block (specified in kernal launch)
blockIdx : gives index of thread block within the grid
gridDim : givces dimension of the grid 

*/