#include <iostream>
#include <time.h>
#include "ltree/ltree.h"
#include "stree/stree.h"
using namespace std;

/***
 * in the function, shadow bplus tree insert key-value pairs
 * @param start
 * @param end
 * @return dur_i
 */
double getInsertTime(clock_t start, clock_t end){

    //build and initial a BPlusTree and a ShadowTree
    LTree *lTree_i = new LTree(32);
    STree *sTree_i = new STree(32);

    //print the BPlusTree and the ShadowTree
    lTree->printTree();
    sTree->printTree();

    //insert Key-Value pairs into the logical tree and the shadow tree
    for(int i = 40000; i <= 50000; i++){
        lTree->insert(i, i * 10);
        sTree->insert(i, i * 10);
    }

    //capture the end time
    end = clock();

    //delete the logical tree and the shadow tree-->delete the allocator as well
    delete lTree;
    delete sTree;
    lTree = NULL;
    sTree = NULL;
    PAllocator::getAllocator()->~PAllocator();

    //get the used time and return it to the main function
    double dur_i = end - start;
    return dur_i
}

/***
 * in the function, shadow bplus tree delete 64 cache lines or key-value pairs
 * @param start, end
 * @return dur_d
 */
double getDeleteTime(clock_t start, clock_t end){
    LTree *lTree = new LTree(32);
    STree *sTree = new STree(32);
    for (int i = 40000; i <= 50000; i++) {
        lTree->delete(i);
        sTree->delete(i);
    }
    end = clock();
    double dur_d = end - start;
    delete lTree;
    delete sTree;
    lTree = NULL;
    sTree = NULL;
    PAllocator::getAllocator()->~PAllocator();
    return dur_d;
}

/***
 * in the function, shadow bplus tree find a key-value pair according to the key
 * @param start, end
 * @return dur_f
 */
double getFindTime(clock_t start, clock_t end){
    LTree *lTree = new LTree(32);
    STree *sTree = new STree(32);
    for (int i = 40000; i <= 50000; i++) {
        lTree->find(i);
        sTree->find(i);
    }
    end = clock();
    double dur_f = end - start;
    delete lTree;
    delete sTree;
    lTree = NULL;
    sTree = NULL;
    PAllocator::getAllocator()->~PAllocator();
    return dur_f;
}

/***
 * in the function, shadow bplus tree change the logical tree and the shadow tree according to the popularity
 * @param start
 * @param end
 * @return
 */
double getUpdateTime(clock_t start, clock_t end){
    LTree *lTree = new LTree(32);
    STree *sTree = new STree(32);
    lTree->update();
    sTree->update();
    end = clock();
    double dur_u = end - start;
    delete lTree;
    delete sTree;
    lTree = NULL;
    sTree = NULL;
    PAllocator::getAllocator()->~PAllocator();
    return dur_u;
}
int main(){

    clock_t start, end;

    //Insert Operations used time
    start = clock();
    double dur_i = getInsertTime(start, end)
    cout<<"Insert Used Time = "<< (dur_i / CLOCKS_PER_SEC) <<endl;

    //Delete Operations used time
    start = clock();
    double dur_d = getDeleteTime(start, end);
    cout<<"Delete Used Time = "<< (dur_d / CLOCKS_PER_SEC) <<endl;

    //Find Operation used time
    start = clock();
    double dur_f = getFindTime(start, end);
    cout<<"Find Used Time = "<< (dur_f / CLOCKS_PER_SEC) <<endl;

    //Update Operations used time
    start = clock();
    double dur_u = getUpdateTime(start, end);
    cout<<"Change Used Time = "<< (dur_u / CLOCKS_PER_SEC) <<endl;

}