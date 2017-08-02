import React, {PureComponent} from 'react';
import {Link} from 'react-router';
import Footer from '../Footer';

class Nav extends PureComponent{

    active(path){

        if(this.props.pathname === path){
            return 'active'
        }
    }

    render(){

        return(
            <div className='container'>
                <div className='wrapper'>
                    <div>
                        <div className="navbar-header">
                            <a className="navbar-brand" href="#">일반설정</a>
                        </div>
                        <div className="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                            <ul className="nav navbar-nav tab">
                                <li className="current" data-tab="internet_info">
                                    <Link to='/' className={this.active('/')}>인터넷 정보</Link>
                                </li>
                                <li data-tab="admin_setting">
                                    <Link to ='/admin' className={this.active('/admin')}>Admin 설정</Link>
                                </li>
                            </ul>
                        </div>
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


export default Nav;
