import React, {PureComponent} from 'react';

class AdminInfo extends PureComponent{

    render(){
        return(

            <div id="admin_setting" className="col-md-8 well tabcontent">
                <h1 className="page-header">
                    <small>Admin 설정</small>
                </h1>
                <div className="table-responsive">
                    <table className="table table-bordered">
                        <tr>
                            <th>SSID변경</th>
                            <td>인터넷에 정상적으로 연결됨</td>
                        </tr>
                        <tr>
                            <th>비밀번호 변경</th>
                            <td>192.168.82.200</td>
                        </tr>
                        <tr>
                            <th>최대 접속 제한</th>
                            <td>인터넷에 정상적으로 연결됨</td>
                        </tr>
                        <tr>
                            <th>비밀번호 횟수제한</th>
                            <td>인터넷에 정상적으로 연결됨</td>
                        </tr>
                    </table>
                    <input type='submit' className="btn btn-default save_config" value="저장" />
                </div>
                <hr />
                <h1 className="page-header">
                    <small>시스템설정</small>
                </h1>
                <div className="col-md-3">
                    <input type='button' className="btn btn-default btn-lg btn-block sys_config" value="시스템 재시작" />
                    <input type='button' className="btn btn-default btn-lg btn-block sys_config" value="초기설정 복원" />
                    <input type='button' className="btn btn-default btn-lg btn-block sys_config" value="자동종료 설정" />
                </div>
            </div>
        );
    }
}

export default AdminInfo;
