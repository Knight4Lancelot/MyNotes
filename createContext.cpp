#include <iostream>
#include <string>
#include <memory>
#include <io.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <sys/stat.h>

static const std::vector<std::string> ignorePath = {
    ".vscode", ".git", "resource", ".gitignore", "temp.md", "README.md", "createContext.exe"
};
static const std::vector<std::string> ignoreSuffix = {
    ".png"
};

class Node {
public:
    Node(Node* node)
        : _layer(node->_layer), _path(node->_path), _name(node->_name) {}
    Node(const std::string& path, const std::string& name, int8_t layer)
        : _path(path), _layer(layer), _name(name) {}
    ~Node() {}

    std::string GetPath()
    {
        return _path;
    }

    std::string GetName()
    {
        return _name;
    }

    int8_t GetLayer()
    {
        return _layer;
    }
protected:
    const std::string _path;
    const std::string _name;
    const int8_t _layer;
};

enum class FileType {
    ERR,
    FILE,
    DIR
};

class Reader {
public:
    std::string TranslateFileTypeName(FileType type)
    {
        switch (type) {
            case FileType::FILE: { return "File"; }
            case FileType::DIR: { return "Dir"; }
            case FileType::ERR:
            default: { return "Error"; }
        }
    }

    FileType CheckPathType(const std::string& path)
    {
        struct stat statInfo;
        stat(path.c_str(), &statInfo);
        if (statInfo.st_mode & S_IFDIR) {
            return FileType::DIR;
        } else if (statInfo.st_mode & S_IFREG) {
            return FileType::FILE;
        } else {
            return FileType::ERR;
        }
    }

    std::vector<std::pair<std::shared_ptr<Node>, FileType>> ReadDir(
        std::shared_ptr<Node> node, bool isNeedSort)
    {
        const std::string root = node->GetPath();
        intptr_t hFile = 0;
        struct _finddata_t fileinfo;
        std::string p(root);
        std::vector<std::pair<std::shared_ptr<Node>, FileType>> res;
        std::vector<std::string> pathList;
        if (p!= ".." && p!= ".") {
            p.append("/*");
        }
        if ((hFile = _findfirst(p.c_str(), &fileinfo))!= -1) {
            do {
                if (strcmp(fileinfo.name, ".")!= 0 && strcmp(fileinfo.name, "..")!= 0) {
                    pathList.push_back(fileinfo.name);
                }
            } while (_findnext(hFile, &fileinfo) == 0);
            _findclose(hFile);
        }
        if (isNeedSort) {
            std::sort(pathList.begin(), pathList.end(), [](const std::string& a, const std::string& b) {
                return a > b;
            });
        }
        for (int i = 0; i < pathList.size(); i++) {
            const std::string nodePath =
                root + pathList[i] + (CheckPathType(root + "/" + pathList[i]) == FileType::DIR? "/" : "");
            std::shared_ptr<Node> ptr = std::make_shared<Node>(
                new Node(nodePath, pathList[i], node->GetLayer() + 1));
            res.push_back(std::make_pair(ptr, CheckPathType(root + "/" + pathList[i])));
        }
        return res;
    }


    bool IsLeafContent(std::map<std::shared_ptr<Node>, FileType> nodeList)
    {
        for (std::pair<std::shared_ptr<Node>, FileType> pair : nodeList) {
            if (pair.second == FileType::DIR) {
                return false;
            }
        }
        return true;
    }

    void PrintFormatPath(std::shared_ptr<Node> node)
    {
        FileType type = CheckPathType(node->GetPath());
        for (int i = 0; i < node->GetLayer() - 1; i++) {
            std::cout << "│&emsp;";
        }
        if (type == FileType::FILE) {
            std::cout << "├─ [" << node->GetName() << "]("
                << node->GetPath() << ")<br>" << std::endl;
        } else if (type == FileType::DIR) {
            std::cout << "├─ **<span style=\"font-size: " <<
                26 - 2 * node->GetLayer() << "px\">"
                << node->GetName() << "</span>**<br>" << std::endl;
        }
    }

    bool IsIgnoreNode(std::string nodeName)
    {
        for (int i = 0; i < ignorePath.size(); i++) {
            if (nodeName == ignorePath[i]) {
                return true;
            }
        }
        return false;
    }

    bool IsIgnoreSuffix(std::string nodeName)
    {
        int lastDotIndex = 0;
        for (int i = nodeName.length() - 1; i >= 0; i--) {
            if (nodeName[i] == '.') {
                lastDotIndex = i;
            }
        }
        std::string suffix = nodeName.substr(lastDotIndex, nodeName.length() - lastDotIndex);
        for (int i = 0; i < ignoreSuffix.size(); i++) {
            if (suffix == ignoreSuffix[i]) {
                return true;
            }
        }
        return false;
    }

    void TraverseFiles(const std::string& root, const std::string& name, bool isNeedSort)
    {
        std::stack<std::pair<std::shared_ptr<Node>, FileType>> fileStack;
        std::vector<std::pair<std::shared_ptr<Node>, FileType>> nodeList;
        std::pair<std::shared_ptr<Node>, FileType> nodeInfo;
        fileStack.push(std::make_pair(std::make_shared<Node>(new Node(root, name, 0)), FileType::DIR));
        while (!fileStack.empty()) {
            nodeInfo = fileStack.top();
            if (!IsIgnoreNode(nodeInfo.first->GetName()) &&
                !IsIgnoreSuffix(nodeInfo.first->GetName())) {
                PrintFormatPath(nodeInfo.first);
            }
            fileStack.pop();
            if (nodeInfo.second == FileType::DIR) {
                nodeList = ReadDir(nodeInfo.first, isNeedSort);
                for (std::pair<std::shared_ptr<Node>, FileType> node: nodeList) {
                    if (!IsIgnoreNode(nodeInfo.first->GetName()) &&
                        !IsIgnoreSuffix(nodeInfo.first->GetName())) {
                        fileStack.push(node);
                    }
                }
            }
        }
    }

private:
    std::string _generateResStr;
};

int main()
{
    Reader reader;
    std::cout << "new tag 1" << std::endl;
    reader.TraverseFiles("./", ".", true);
}
