# Shopper

## 基本功能

一个商品清单和一个计数器。一个添加商品按钮，一个完成商品按钮，一个删除商品按钮，一个计数器增量按钮。

没啥别的要说的了。

## 界面设计

写在上面了 btnAddCommodity, btnBuyCommodity, btnDeleteCommodity, btnMakeMoney

排在下面排成一排

上面是一个列表框

| 功能      | 描述                             |
| --------- | -------------------------------- |
| AddCom    | 弹出两次输入对话框输入名称和价格 |
| BuyCom    | 根据列表框的选项来判断你买了啥   |
| DelCom    | 根据列表框的选项来判断你想删掉啥 |
| MakeMoney | 直接操作计数器                   |

## 类设计

我们单独封装一个类叫做 Status，里面存了整个商品清单和计数器

每次修改任何参数后，调用 Status 的 write() 方法写入

每次打开程序时，调用 Status 的 read() 方法读取

文件保存在程序目录下的 status 文件中

Status 会为每个功能流出接口，图形界面直接调用这些接口即可

图形界面用一个 MainWindow 来设计，按钮和菜单各提供一份

## Todolist

| 状态 | 内容                   | 时间 |
| ---- | ---------------------- | ---- |
| +    | 写计划书               | 2    |
| +1   | 画界面                 | 1    |
| +    | 写 Status 模块基本操作 | 1    |
| +1   | 写交互并调试           | 2    |
| +    | 菜单实现               | 1    |
| +    | 写 Status 模块文件读写 | 1    |
| +1   | 系统托盘               | 1    |
|      | （保留）               | 1    |

