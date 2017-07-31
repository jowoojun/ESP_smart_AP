import React, {PureComponent} from 'react';

class Nav extends PureComponent{

    render(){

        return(
            <div>
                <div className="navbar-header">
                    <a className="navbar-brand" href="#">일반설정</a>
                </div>
                <div className="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                    <ul className="nav navbar-nav tab">
                        <li className="current" data-tab="internet_info">
                            <a href="#">인터넷 정보</a>
                        </li>
                        <li data-tab="admin_setting">
                            <a href="#">Admin 설정</a>
                        </li>
                    </ul>
                </div>
            </div>

        );
    }
}


export default Nav;
