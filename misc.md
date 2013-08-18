# ちょっとどうしようもないもの

**順番めちゃくちゃ。あとで整理。**

#### 日本語音声ファイル適用

オリジナルは以下。

- http://ftp.voip-info.jp/asterisk/sounds/1_8/asterisk-sounds-1.8-ja.tar.gz

<pre>
mkdir /usr/src/asterisk/src/sounds/
cd /usr/src/asterisk/src/sounds/
wget http://ftp.voip-info.jp/asterisk/sounds/1_8/asterisk-sounds-1.8-ja.tar.gz
tar xvzf asterisk-sounds-1.8-ja.tar.gz -C /var/lib/asterisk/sounds
</pre>

<pre>
# /etc/asterisk/asterisk.conf
[options]
languageprefix=yes
language=ja
</pre>

## configディレクトリについて

### config/asterisk/

自宅のAsterisk設定が格納されています。  
実際に配備する際はGitリポジトリでの設定ファイル管理の都合も考えて以下のようにシンボリックリンクを張るようにしたほうがいいかもしれません。  
あとでシェルスクリプト用意しとくよ。

```
ln -s /usr/src/asterisk/config/asterisk /etc/asterisk
```

### resources/sounds/ and resources/moh/

音声ファイルについても同様です。

```
ln -s /usr/src/asterisk/src/resources/sounds/ja /var/lib/asterisk/sounds/ja
```

保留の音声等は他のディレクトリに入っているようなのでこれは以下のようにします。

```
ln -s /usr/src/asterisk/src/resources/moh/ /var/lib/asterisk/moh
```

### IAXmodemインストール時の注意について

設定ディレクトリもバージョン管理しているのでシンボリックリンクを張ります。

```
ln -s /usr/src/asterisk/src/config/iaxmodem /etc/iaxmodem
```

#### libiax2

ライブラリ登録で `/usr/local/lib` がなければ、ここで追加しておきます。
`ldconfig` コマンドで、登録できてることを確認しておきます。

```
[root@asterisk libiax2]# echo /usr/local/lib > /etc/ld.so.conf.d/usr_local_lib.conf
[root@asterisk libiax2]# /sbin/ldconfig -v | grep libiax
/sbin/ldconfig: /etc/ld.so.conf.d/kernel-2.6.32-358.el6.x86_64.conf:6: duplicate hwcap 1 nosegneg
        libiax.so.0 -> libiax.so.0.0.0
```

#### spandsp

こちらも、 `ldconfig` コマンドで、登録できてることを確認しておきます。

```
[root@asterisk spandsp]# /sbin/ldconfig -v | grep libspandsp
/sbin/ldconfig: /etc/ld.so.conf.d/kernel-2.6.32-358.el6.x86_64.conf:6: duplicate hwcap 1 nosegneg
        libspandsp.so.1 -> libspandsp.so.1.0.0
```

```
wget http://downloads.asterisk.org/pub/telephony/asterisk/releases/asterisk-11.0.1.tar.gz
wget http://downloads.asterisk.org/pub/telephony/dahdi-linux-complete/dahdi-linux-complete-current.tar.gz
wget http://downloads.asterisk.org/pub/telephony/libpri/libpri-1.4.13.tar.gz
```
