//
//  FileListAttrWrapper.h
//  SwiftCpp04
//
//  Created by uwe on 15.02.22.
//

#ifndef FileListAttrWrapper_h
#define FileListAttrWrapper_h

#import <Foundation/Foundation.h>

@interface FileListAttrWrapper : NSObject
- (NSMutableArray<NSMutableArray<NSString *> *> *) sayFileListAttr:(const char*)dirName;

@end

#endif /* FileListAttrWrapper_h */
