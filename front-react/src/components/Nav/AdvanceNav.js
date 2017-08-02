import React, {PureComponent} from 'react';
import {Link} from 'react-router'
import Footer from '../Footer';

class AdvanceNav extends PureComponent{

    render(){

        return(
            <div className='container'>
                <div className='wrapper'>
                    <div className="navbar-header">
                        <a className="navbar-brand" href="#">고급설정</a>
                    </div>

                    <div className="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                        <ul className="nav navbar-nav menu tab">
                            <li><a href="#">네트워크관리</a>
                                <ul className="sub">
                                    <li className="current" data-tab="dynamic_ip">유동 IP/고정IP</li>
                                </ul>
                            </li>
                            <li><a href="#">유해사이트차단</a>
                                <ul className="sub">
                                    <li data-tab="block_word">특정단어차단</li>
                                    <li data-tab="block_site">유해사이트차단</li>
                                </ul>
                            </li>
                            <li className="active_tab" data-tab="blacklist"><a href="#">블랙리스트</a>
                                <ul className="sub">
                                    <li data-tab="blacklist">블랙리스트</li>
                                </ul>
                            </li>
                            <li><a href="#">NAT/Router</a>
                                <ul className="sub">
                                    <li data-tab="port_forwarding">포트포워딩</li>
                                    <li data-tab="twin_ip">트윈 IP</li>
                                </ul>
                            </li>
                            <li><a href="#">시스템관리</a>
                                <ul className="sub">
                                    <li data-tab="system_log">System Log</li>
                                    <li data-tab="firmware">펌웨어</li>
                                </ul>
                            </li>
                            <li><a href="general_settings.html">HOME</a></li>
                        </ul>
                    </div>
                    <div className='row'>
                        {this.props.children}
                    </div>
                    <Footer />
                </div>
            </div>
        );
    }
}


export default AdvanceNav;
