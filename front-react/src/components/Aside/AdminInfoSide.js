import React, {PureComponent} from 'react';

class AdminInfoAside extends PureComponent{

    render(){

        return(
            <div className='col-md-4'>
                <div className="well tabcontent" id="admin_setting_desc">
                    <h4>설명</h4>
                      <ul>
                        <li>SSID :</li>
                        <li>비밀번호 :</li>
                        <li>최대접속제한 :</li>
                      </ul>
                </div>
            </div>
        );
    }
}

export default AdminInfoAside;
