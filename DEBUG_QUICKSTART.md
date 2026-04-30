# 调试模式快速使用指南

## 🚀 快速开始

### Windows 用户

```powershell
# 运行交互式构建脚本
.\debug-build.bat

# 选择选项 1 (Debug 模式)
```

### Linux/macOS 用户

```bash
# 添加执行权限并运行
chmod +x debug-build.sh
./debug-build.sh

# 选择选项 1 (Debug 模式)
```

## 📋 手动配置

### Windows
```powershell
cmake -DCMAKE_BUILD_TYPE=Debug .
cmake --build . --config Debug
```

### Linux/macOS
```bash
cmake -DCMAKE_BUILD_TYPE=Debug .
make -j 4
```

## 🔍 调试工具

### GDB (Linux/macOS)
```bash
gdb ./bin/phpx-tests
(gdb) run
(gdb) bt          # 查看堆栈
(gdb) print var   # 查看变量
```

### Visual Studio (Windows)
1. 打开生成的 `.sln` 文件
2. 设置断点
3. 按 F5 开始调试

### Valgrind (Linux/macOS)
```bash
valgrind --leak-check=full ./bin/phpx-tests
```

## 📚 更多文档

- [详细调试指南](docs/debugging-guide.md)
- [快速参考](docs/debugging-quick-reference.md)
- [功能说明](DEBUG_FEATURES.md)
- [实现总结](IMPLEMENTATION_SUMMARY.md)

## ✨ Debug 模式特性

- ✅ 完整的调试符号
- ✅ 禁用优化（便于调试）
- ✅ 运行时错误检查（Windows）
- ✅ 详细的编译输出
- ✅ 支持断点调试和堆栈跟踪

## ⚠️ 注意事项

- Debug 模式运行速度较慢，仅用于开发调试
- 发布前请切换到 Release 模式
- 确保 `.dll` 和 `.pdb` 在同一目录（Windows）

---

*需要帮助？查看 [debugging-guide.md](docs/debugging-guide.md)*
