---
title: android partitions
date: 2022-11-12 20:00:01
tags:
---

```bash
walleye:/bin # parted /dev/block/sda
GNU Parted 3.4
Using /dev/block/sda
Welcome to GNU Parted! Type 'help' to view a list of commands.
(parted) p
Model: SAMSUNG KLUCG4J1ED-B0C1 (scsi)
Disk /dev/block/sda: 63.8GB
Sector size (logical/physical): 4096B/4096B
Partition Table: gpt
Disk Flags:

Number  Start   End     Size    File system  Name          Flags
 1      24.6kB  65.5kB  41.0kB               padding0      msftdata
 2      65.5kB  590kB   524kB                lockbooter_a
 3      590kB   1114kB  524kB                rpm_a
 4      1114kB  3211kB  2097kB               tz_a
 5      3211kB  3736kB  524kB                hyp_a
 6      3736kB  4260kB  524kB                pmic_a
 7      4260kB  88.1MB  83.9MB               modem_a       msftdata
 8      88.1MB  89.2MB  1049kB               abl_a
 9      89.2MB  123MB   33.6MB               boot_a
10      123MB   156MB   33.6MB               hosd_a
11      156MB   157MB   524kB                keymaster_a
12      157MB   157MB   524kB                cmnlib_a
13      157MB   158MB   524kB                cmnlib64_a
14      158MB   158MB   262kB                apdp_a
15      158MB   158MB   262kB                msadp_a
16      158MB   159MB   131kB                devcfg_a
17      159MB   159MB   131kB                storsec_a
18      159MB   159MB   65.5kB               vbmeta_a
19      159MB   162MB   3146kB               trusty_a
20      162MB   686MB   524MB   ext2         vendor_a      msftdata
21      686MB   695MB   8389kB               dtbo_a
22      695MB   3379MB  2684MB  ext2         system_a
23      3379MB  3379MB  524kB                lockbooter_b
24      3379MB  3380MB  524kB                rpm_b
25      3380MB  3382MB  2097kB               tz_b
26      3382MB  3383MB  524kB                hyp_b
27      3383MB  3383MB  524kB                pmic_b
28      3383MB  3467MB  83.9MB               modem_b
29      3467MB  3468MB  1049kB               abl_b
30      3468MB  3502MB  33.6MB               boot_b
31      3502MB  3535MB  33.6MB               hosd_b
32      3535MB  3536MB  524kB                keymaster_b
33      3536MB  3536MB  524kB                cmnlib_b
34      3536MB  3537MB  524kB                cmnlib64_b
35      3537MB  3537MB  262kB                apdp_b
36      3537MB  3537MB  262kB                msadp_b
37      3537MB  3537MB  131kB                devcfg_b
38      3537MB  3538MB  131kB                storsec_b
39      3538MB  3538MB  65.5kB               vbmeta_b
40      3538MB  3541MB  3146kB               trusty_b
41      3541MB  4065MB  524MB   ext2         vendor_b
42      4065MB  4073MB  8389kB               dtbo_b
43      4073MB  6758MB  2684MB  ext2         system_b
44      6758MB  6761MB  3473kB               padding1      msftdata
45      6761MB  63.8GB  57.1GB  ext4         userdata

(parted)
walleye:/bin #
walleye:/bin # parted /dev/block/sdb
GNU Parted 3.4
Using /dev/block/sdb
Welcome to GNU Parted! Type 'help' to view a list of commands.
(parted) p
Model: SAMSUNG KLUCG4J1ED-B0C1 (scsi)
Disk /dev/block/sdb: 4194kB
Sector size (logical/physical): 4096B/4096B
Partition Table: gpt
Disk Flags:

Number  Start   End     Size    File system  Name   Flags
 1      24.6kB  4174kB  4149kB               xbl_a

(parted)
walleye:/bin # parted /dev/block/sdc
GNU Parted 3.4
Using /dev/block/sdc
Welcome to GNU Parted! Type 'help' to view a list of commands.
(parted) p
Model: SAMSUNG KLUCG4J1ED-B0C1 (scsi)
Disk /dev/block/sdc: 4194kB
Sector size (logical/physical): 4096B/4096B
Partition Table: gpt
Disk Flags:

Number  Start   End     Size    File system  Name   Flags
 1      24.6kB  4174kB  4149kB               xbl_b

(parted)
walleye:/bin # parted /dev/block/sdd
GNU Parted 3.4
Using /dev/block/sdd
Welcome to GNU Parted! Type 'help' to view a list of commands.
(parted) p
Model: SAMSUNG KLUCG4J1ED-B0C1 (scsi)
Disk /dev/block/sdd: 101MB
Sector size (logical/physical): 4096B/4096B
Partition Table: gpt
Disk Flags:

Number  Start   End     Size    File system  Name      Flags
 1      24.6kB  1073kB  1049kB               misc
 2      1073kB  1081kB  8192B                ssd
 3      1081kB  34.6MB  33.6MB  ext4         persist
 4      34.6MB  35.2MB  524kB                frp
 5      35.2MB  35.2MB  4096B                cdt
 6      35.2MB  36.2MB  1049kB               ddr
 7      36.2MB  36.3MB  131kB                sec
 8      36.3MB  37.4MB  1049kB               dip
 9      37.4MB  37.4MB  4096B                dpo
10      37.4MB  71.6MB  34.2MB               splash
11      71.6MB  71.6MB  4096B                limits
12      71.6MB  72.7MB  1049kB               toolsfv
13      72.7MB  81.1MB  8389kB               logfs
14      81.1MB  83.2MB  2097kB               sti
15      83.2MB  85.3MB  2097kB               modemst1
16      85.3MB  87.4MB  2097kB               modemst2
17      87.4MB  88.4MB  1049kB               fsc
18      88.4MB  101MB   12.2MB               reserve3  msftdata

(parted)
walleye:/bin # parted /dev/block/sde
GNU Parted 3.4
Using /dev/block/sde
Welcome to GNU Parted! Type 'help' to view a list of commands.
(parted) p
Model: SAMSUNG KLUCG4J1ED-B0C1 (scsi)
Disk /dev/block/sde: 37.7MB
Sector size (logical/physical): 4096B/4096B
Partition Table: gpt
Disk Flags:

Number  Start   End     Size    File system  Name      Flags
 1      24.6kB  6316kB  6291kB               ramdump
 2      6316kB  10.5MB  4194kB               pg1fs
 3      10.5MB  12.6MB  2097kB               pg2fs
 4      12.6MB  29.4MB  16.8MB  ext4         metadata  msftdata
 5      29.4MB  37.7MB  8344kB               reserve4  msftdata

(parted)
walleye:/bin # parted /dev/block/sdf
GNU Parted 3.4
Using /dev/block/sdf
Welcome to GNU Parted! Type 'help' to view a list of commands.
(parted) p
Model: SAMSUNG KLUCG4J1ED-B0C1 (scsi)
Disk /dev/block/sdf: 8389kB
Sector size (logical/physical): 4096B/4096B
Partition Table: gpt
Disk Flags:

Number  Start   End     Size    File system  Name        Flags
 1      24.6kB  41.0kB  16.4kB               board_info
 2      41.0kB  303kB   262kB                mfg
 3      303kB   1876kB  1573kB               fsg
 4      1876kB  1880kB  4096B                devinfo
 5      1880kB  8368kB  6488kB               reserve5    msftdata

```