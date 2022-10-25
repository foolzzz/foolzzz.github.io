---
title: 折腾arch
date: 2022-10-17 16:33:30
tags: archlinux
---


### xorg
sudo pacman -S xorg-server xorg-apps xorg-xinit xorg-xclock xterm 

### kde plasma
sudo pacman -S plasma
sudo pacman -S kde-applications

### 登录管理器
sddm: simple desktop display manager

sudo pacman -S sddm
sudo systemctl enable sddm
sudo systemctl start sddm


X是协议，不是某个软件.
X11R6 是 X协议的Release 6版本


twm是什么
TabWindow Manager for the X WindowSystem. 是一个窗口管理器

终端模拟器
sTerm, Rxvt, Konsole, Kvt, Gnome-Terminal, Nxterm, eterm



xrdp



run level [inittab详解](https://blog.csdn.net/newnewman80/article/details/8133797)
0 - 关闭或暂停系统 | shutdown.target
1 - 单用户模式 | rescue.target
2 - 多用户, 没有NFS | multi-user.target
3 - 完全多用户 | multi-user.target
4 - 保留 | multi-user.target
5 - X11(图形用户界面) | graphical.target
6 - 重启系统 | reboot.target


### systemd
http://blog.itpub.net/31524109/viewspace-2647049/


Display manager: https://wiki.archlinux.org/title/Display_manager_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)




dwm安装
https://blog.csdn.net/qq_45933858/article/details/124553077

kde是桌面

DM: https://wiki.archlinux.org/title/Display_manager_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)
DM是显示管理器, 也叫登录管理器。
SDDM - Simple Desktop Display Manager
不同DM的区别 https://blog.csdn.net/weixin_36073714/article/details/116758417
WM(Window Manager)


REF:
https://www.cnblogs.com/EasonJim/p/7230616.html
https://www.jianshu.com/p/a05559a7b757
https://jtao.work/archives/x--w-i-n-d-o-w--she-zhi-jie-shao
[deepin lighdm配置](https://wiki.archlinux.org/title/Deepin_Desktop_Environment_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))
[Window Manager](https://wiki.archlinux.org/title/Window_manager_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))
[KDE plasma](https://wiki.archlinux.org/title/KDE_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)#%E5%90%AF%E5%8A%A8_Plasma)
[/etc/inittab](https://blog.csdn.net/ChunfengZhang/article/details/4450531)
[arch inittab](https://wiki.archlinux.org/title/SysVinit_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))
[ubuntu](https://blog.csdn.net/yusiguyuan/article/details/9928139)