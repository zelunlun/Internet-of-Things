# Internet-of-Things

### 20230427

> VM ID: IoT </br>
> VM Passwd: isuCSIE2023#

* 修改檔案
    1. 遠端桌面內的`mosquitto/` 裡面的 `mosquitto.conf`
    2. 尋找 `listener`, 把裡面的註解打開
    3. 並改成 `listener 1883`

* 重新設置密碼
    1. 開啟CMD
    2. 先 `cd C:\Program Files\mosquitto`
    3. 再輸入 `mosquitto_passwd -c passwd iot`
    4. 產生 `passwd` 這個檔即成功
    5. 再將 `mosquitto.conf` 裡面第550行的 `passwd_file`後面加上 `pass`這個檔案的路徑