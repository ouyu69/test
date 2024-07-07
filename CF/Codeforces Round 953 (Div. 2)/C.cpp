// void Arr1(string s){
//     PWI te = findArr(s);
//     Word out1 = te.first ;
//     sum_ASL += te.second ;
//     len1 += te.second ;
//     cout << "顺 序 表 的 顺 序 査 找：" << endl ;
//     if(out1.data.size()){ 
//         cout << "已经找到:" << endl ;
//         cout << out1.data << " " << (double)(out1.fre / (double)all) * 100 << "%" << endl ;
//     }else{
//         cout << "查找失败！" << endl ;
//     }
    
// }
// void List(string s,ListNode * L){
//     PWI te = findList(s,L) ;
//     Word out2 = te.first ;
//     sum_ASL += te.second ;
//     len2 += te.second ;
//     cout << "链 表 的 顺 序 查 找：" << endl ;
//     if(out2.data.size()){
//         cout << "已经找到:" << endl ;
//         cout << out2.data << " " << double(out2.fre / (double)all) * 100 << "%" << endl ;
//     }else{
//         cout << "查找失败！" << endl ;
//     }
// }
// void Bainart(string s,int sum){
//     PWI te = findBinart(0,sum-1,s) ;
//     Word out3 = te.first ;
//     sum_ASL += te.second ;
//     len3 += te.second ;
//     cout << "顺 序 表 的 折 半 查 找：" << endl ;
//     if(out3.data.size()){
//         cout << "已经找到:" << endl ;
//         cout << out3.data << " " << double(out3.fre / (double)all)*100 << "%" << endl ;
//     }else{
//         cout << "查找失败！" << endl ;
//     }
// }
// void Tree(string s,TreeNode * t){
//     cout << "二 叉 排 序 树 的 査 找：" << endl;
//     int len = 0 ;
//     TreeNode *p = findTree(t,s,len) ;
//     len4 += len ;
//     sum_ASL += len ;
//     if(p != NULL){
//         Word out4 = p->data ;
//         cout << "已经找到：" << endl ;
//         cout << out4.data << " " << double(out4.fre / (double)all) * 100 << "%" << endl ;
//     }else{
//         cout << "查找失败！" << endl ;  
//     }
// }
// void funHash1(string s){
//     PWI te = findHash1(s) ;
//     Word out5 = te.first ;
//     sum_ASL += te.second ;
//     len5 += te.second ;
//     cout << "开 放 地 址 法 的 哈 希 查 找：" << endl ;
//     if(out5.data.size()){
//         cout << "已经找到：" << endl ;
//         cout << out5.data << " " << double(out5.fre / (double)all) * 100 << "%" << endl ;
//     }else{
//         cout << "查找失败！" << endl ;
//     }
// }
// void funHash2(string s){
//     PWI te = findHash2(s) ;
//     Word out6 = te.first ;
//     sum_ASL += te.second ;
//     len6 += te.second ;
//     cout << "链 地 址 法 的 哈 希 查 找：" << endl ;
//     if(out6.data.size()){
//         cout << "已经找到：" << endl ;
//         cout << out6.data << " " << double(out6.fre / (double)all) * 100 << "%" << endl ;
//     }else{
//         cout << "没有找到！" << endl ;
//     }
// }