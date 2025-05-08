from pydantic import BaseModel
import json

class Task(BaseModel):
    threadId: int = 0  # 对应 Go 的 Tid (int64)
    timestamp: int = 0  # 对应 Go 的 Ts (time.Duration, ns since epoch)
    endTs: int = 0  # 对应 Go 的 EndTs (time.Duration, ns since epoch)
    sqlType: str = ""  # Go 的 SQLType，假设用字符串表示
    sql: str = ""
    sqlDigest: str = ""
    dbName: str = ""
    
class NormalTask():
    threadId: int = 0  # 对应 Go 的 Tid (int64)
    timestamp: int = 0  # 对应 Go 的 Ts (time.Duration, ns since epoch)
    endTs: int = 0  # 对应 Go 的 EndTs (time.Duration, ns since epoch)
    sqlType: str = ""  # Go 的 SQLType，假设用字符串表示
    sql: str = ""
    sqlDigest: str = ""
    dbName: str = ""
    
if __name__ == "__main__":
    # 1. 测试基本的初始化
    t = Task()
    print(f"1: {t}")
    
    # 2. 测试用dict初始化
    d = {
        "threadId": 123,
        "timestamp": 1620000000000000000,
        "endTs": 1620000001000000000,
        "sqlType": "SELECT",
        "sql": "SELECT * FROM users",
        "sqlDigest": "a1b2c3d4",
        "dbName": "test_db"
    }
    t2 = Task(**d)
    print(f"2: {t2}")
    
    # 3. 测试更新
    t.__dict__.update(d)
    print(f"3: {t}")
    
    # 4. 测试序列化
    # print(json.dumps(t)) 报错，直接尝试序列化Pydantic模型对象，而json模块不知道如何序列化自定义类对象。
    print(f"4: {t.model_dump_json()}")
    
    # 5. 验证普通类可以直接序列化吗
    nt = NormalTask()
    nt.threadId = 123
    print(f"5: {json.dumps(nt.__dict__)}")