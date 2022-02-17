//
//  FileListAttrWrapper.mm
//  
//
//  Created by uwe on 17.02.22.
//

#import <Foundation/Foundation.h>

#import "FileListAttrWrapper.h"
#import "FileListAttr.h"

@implementation FileListAttrWrapper
- (NSArray<NSArray<NSString *> *> *) sayFileListAttr:(const char*)dirName
{
    FileListAttr fileListAttr;
    string DirName(dirName);
    
    NSMutableArray<NSMutableArray<NSString *> *> *ret;
    ret = [[NSMutableArray alloc] init];
    
    vector<vector<string>> fileListMessage = fileListAttr.sayFileListAttr(DirName);
    
    for (auto listMembers: fileListMessage) {
        NSMutableArray<NSString *> *wrkRet;
        wrkRet = [[NSMutableArray alloc] init];
        for (auto listMem: listMembers) {
            
            [wrkRet addObject:[NSString stringWithCString:listMem.c_str()encoding:NSUTF8StringEncoding]];
        }
        [ret addObject:wrkRet];
    }
 
    return ret;
}
@end
